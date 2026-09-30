import argparse
import csv
import json
import os
import sys
import threading
import time
from concurrent.futures import ThreadPoolExecutor, as_completed

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import client as client_mod
import normalize
import prompt as prompt_mod
import sources
from store import ResultStore, code_hash

HERE = os.path.dirname(os.path.abspath(__file__))
DEFAULT_ROOT = os.path.join(os.path.dirname(HERE), "infoarena")
DEFAULT_OUT = os.path.join(os.path.dirname(HERE), "labels")

PRICES = {
    "deepseek-chat": (0.27, 0.07, 1.10),
    "deepseek-reasoner": (0.55, 0.14, 2.19),
    "deepseek-v4-flash": (0.44, 0.014, 1.32),
    "deepseek-v4-pro": (1.32, 0.044, 3.96),
}
DEFAULT_PRICE = PRICES["deepseek-chat"]


def prices(model):
    name = (model or "").lower()
    for key, tariff in PRICES.items():
        if name == key or name.endswith("/" + key):
            return tariff
    return DEFAULT_PRICE


def classify(llm, system, row, code):
    data = llm.complete_json(system, prompt_mod.build_user(row, code))
    algorithm = str(data.get("algorithm") or "").strip()
    unoptimized = data.get("unoptimized")
    if isinstance(unoptimized, str):
        unoptimized = unoptimized.strip().lower() in ("true", "yes", "1", "da")
    try:
        confidence = float(data.get("confidence", 0.0))
    except (TypeError, ValueError):
        confidence = 0.0
    evidence = str(data.get("evidence") or "").strip()[:200]
    if unoptimized and normalize.key(evidence) == "standardform":
        unoptimized = False
    return algorithm, bool(unoptimized), confidence, evidence


def _record(row, digest, algorithm, unoptimized, confidence, label, model,
            evidence=""):
    return {"id": row["id"], "hash": digest, "algorithm": algorithm,
            "unoptimized": unoptimized, "confidence": confidence,
            "label": label, "model": model, "evidence": evidence,
            "ts": int(time.time())}


def stratified_sample(pairs, size):
    buckets = {}
    for row, code in pairs:
        try:
            score = int(row.get("score") or 0)
        except ValueError:
            score = 0
        buckets.setdefault(min(score // 10, 10), []).append((row, code))
    sample, index = [], 0
    keys = sorted(buckets)
    while len(sample) < size and any(len(b) > index for b in buckets.values()):
        for k in keys:
            if len(buckets[k]) > index and len(sample) < size:
                sample.append(buckets[k][index])
        index += 1
    return sample


def discover_vocabulary(llm, name, meta, pairs, seed_labels, sample_size, workers,
                        verbose=True):
    vocab = normalize.Vocabulary()
    for label in seed_labels:
        algorithm, _ = normalize.split(label)
        if algorithm:
            vocab.resolve(algorithm)
    if verbose and vocab.canonical:
        print("  seeded from existing labels: %s" % ", ".join(vocab.canonical))

    sample = stratified_sample(pairs, sample_size)
    if not sample:
        return vocab
    system = prompt_mod.build_system(name, meta)
    counts = {}
    with ThreadPoolExecutor(max_workers=workers) as pool:
        futures = {pool.submit(classify, llm, system, row, code): row
                   for row, code in sample}
        for future in as_completed(futures):
            try:
                algorithm, _unopt, _conf, _why = future.result()
            except Exception as exc:
                print("  discovery call failed: %s" % exc, file=sys.stderr)
                continue
            algorithm = normalize.clean(algorithm)
            if algorithm:
                counts[algorithm] = counts.get(algorithm, 0) + 1
    if verbose:
        print("  discovery saw %d distinct raw names over %d submissions"
              % (len(counts), len(sample)))

    merged = consolidate(llm, counts, vocab)
    return merged


CONSOLIDATE_TOKENS = 3000


def consolidate(llm, counts, vocab):
    if not counts:
        return vocab
    listing = "\n".join("%s: %d" % (n, c)
                        for n, c in sorted(counts.items(), key=lambda kv: -kv[1]))
    known = "\n".join(vocab.canonical)
    user = "Raw names with counts:\n%s\n" % listing
    if known:
        user += ("\nThese canonical names are already fixed for this problem and must "
                 "be kept as-is; map raw names onto them where they fit:\n%s\n" % known)
    try:
        data = llm.complete_json(prompt_mod.CONSOLIDATE_SYSTEM, user,
                                 max_tokens=CONSOLIDATE_TOKENS)
    except Exception as exc:
        print("  consolidation failed (%s); using fuzzy merge" % exc, file=sys.stderr)
        for name in sorted(counts, key=lambda n: -counts[n]):
            vocab.resolve(name)
        return vocab

    for raw, target in (data.get("aliases") or {}).items():
        if normalize.clean(target):
            vocab._aliases[normalize.key(raw)] = normalize.clean(target)
    for name in (data.get("canonical") or []):
        vocab.add(name)
    for name in sorted(counts, key=lambda n: -counts[n]):
        vocab.resolve(name)
    return vocab


def _follows_convention(label, algorithm, unoptimized):
    written = " ".join((label or "").lower().split())
    expected = " ".join(normalize.compose(algorithm, unoptimized).lower().split())
    return written == expected


def pick_examples(source, rows, count):
    if count <= 0:
        return [], []
    by_algo, sides = {}, {True: [], False: []}
    for row in sorted(rows, key=lambda r: str(r["id"])):
        if not row.get("label"):
            continue
        algorithm, unoptimized = normalize.split(row["label"])
        if not algorithm or not _follows_convention(row["label"], algorithm,
                                                    unoptimized):
            continue
        by_algo.setdefault(normalize.key(algorithm), {True: [], False: []})[
            unoptimized].append((row, algorithm))
        sides[unoptimized].append((row, algorithm))
    if not sides[True] or not sides[False]:
        return [], []

    paired = [key for key in sorted(by_algo)
              if by_algo[key][True] and by_algo[key][False]]
    paired.sort(key=lambda k: -(len(by_algo[k][True]) + len(by_algo[k][False])))

    chosen, seen = [], set()
    depth = 0
    while paired and len(chosen) < count:
        progressed = False
        for key in paired:
            for flag in (False, True):
                bucket = by_algo[key][flag]
                if len(bucket) > depth and len(chosen) < count:
                    chosen.append(bucket[depth])
                    seen.add(str(bucket[depth][0]["id"]))
                    progressed = True
        if not progressed:
            break
        depth += 1
    for index in range(count * 2):
        if len(chosen) >= count:
            break
        side = sides[bool(index % 2)]
        if len(side) > index // 2:
            candidate = side[index // 2]
            if str(candidate[0]["id"]) not in seen:
                chosen.append(candidate)
                seen.add(str(candidate[0]["id"]))
    examples, ids = [], []
    for row, algorithm in chosen:
        code = source.code(row["id"])
        if not code:
            continue
        examples.append((algorithm, normalize.split(row["label"])[1], code))
        ids.append(str(row["id"]))
    return examples, ids


NO_WEAK = ("no weaker variant of this appears among the labelled submissions "
           "for this problem; answer false")

VARIANT_CODE_CHARS = 2000


def derive_variants(llm, source, rows, vocabulary, per_side=2):
    graded = {}
    for row in sorted(rows, key=lambda r: str(r["id"])):
        if not row.get("label"):
            continue
        algorithm, unoptimized = normalize.split(row["label"])
        if not algorithm or not _follows_convention(row["label"], algorithm,
                                                    unoptimized):
            continue
        graded.setdefault(normalize.key(algorithm), {True: [], False: []})[
            unoptimized].append(row)

    variants = {}
    for algorithm in vocabulary:
        sides = graded.get(normalize.key(algorithm))
        if not sides or not sides[False]:
            continue
        blocks = []
        for flag, caption in ((False, "standard"), (True, "weak")):
            for row in sides[flag][:per_side]:
                code = source.code(row["id"])
                if code:
                    blocks.append('The human labelled this "%s":\n```\n%s\n```'
                                  % (caption, prompt_mod.clip(code,
                                                              VARIANT_CODE_CHARS)))
        if not blocks:
            continue
        if not sides[True]:
            blocks.append("No submission to this problem was labelled as the "
                          "weaker variant of this algorithm.")
        user = prompt_mod.VARIANT_USER.format(algorithm=algorithm,
                                              blocks="\n\n".join(blocks))
        try:
            data = llm.complete_json(prompt_mod.VARIANT_SYSTEM, user,
                                     max_tokens=CONSOLIDATE_TOKENS)
        except Exception as exc:
            print("  variant spec for %s failed: %s" % (algorithm, exc),
                  file=sys.stderr)
            continue
        standard = str(data.get("standard") or "").strip()
        weak = str(data.get("weak") or "").strip()
        if not sides[True]:
            weak = NO_WEAK
        if standard and weak:
            variants[algorithm] = {"standard": standard, "weak": weak}
    return variants


def save_examples(path, ids):
    with open(path, "w", encoding="utf-8") as fh:
        json.dump({"ids": ids}, fh, indent=2)


def load_example_ids(path):
    if not os.path.isfile(path):
        return set()
    try:
        with open(path, encoding="utf-8") as fh:
            return set(json.load(fh).get("ids") or [])
    except (ValueError, OSError):
        return set()


def announce_hand_labels(source):
    for path, count in source.hand_labels:
        print("  %d hand labels merged in from %s" % (count, path))


def label_problem(args, name):
    source = sources.ProblemSource(args.root, name)
    try:
        rows = source.rows()
        announce_hand_labels(source)
        meta = source.meta()
        editorial = source.solution() if args.editorial else None

        os.makedirs(args.out, exist_ok=True)
        store = ResultStore(os.path.join(args.out, "%s.jsonl" % name))
        vocab_path = os.path.join(args.out, "%s.vocab.json" % name)
        examples_path = os.path.join(args.out, "%s.examples.json" % name)

        wanted = [row for row in rows
                  if args.force or store.get(row["id"]) is None]
        if args.limit:
            wanted = wanted[:args.limit]
        if not wanted:
            print("%s: %d rows, all already labelled; writing back"
                  % (name, len(rows)))
            write_back(args, source, rows, store)
            return

        todo, missing = [], 0
        for row in wanted:
            code = source.code(row["id"])
            if not code:
                missing += 1
                continue
            todo.append((row, code))

        print("%s: %d rows, %d to label%s"
              % (name, len(rows), len(todo),
                 ", %d without scraped source" % missing if missing else ""))
        if not todo:
            write_back(args, source, rows, store)
            return
        pairs = todo

        llm = client_mod.build_client(args)

        if os.path.isfile(vocab_path) and not args.rediscover:
            vocab = normalize.Vocabulary.from_dict(json.load(open(vocab_path)))
            print("  vocabulary (cached): %s" % ", ".join(vocab.canonical))
        else:
            seed = [row.get("label", "") for row in rows if row.get("label")]
            vocab = discover_vocabulary(llm, name, meta, pairs, seed,
                                        args.sample, args.workers)
            print("  vocabulary: %s" % ", ".join(vocab.canonical))
        save_vocab(vocab_path, vocab)

        examples, example_ids = pick_examples(source, rows, args.examples)
        save_examples(examples_path, example_ids)
        if examples:
            print("  %d hand-labelled examples pinned into the prompt (%d weak, "
                  "%d standard)" % (len(examples),
                                    sum(1 for e in examples if e[1]),
                                    sum(1 for e in examples if not e[1])))
        if args.variants and (not vocab.variants or args.rediscover):
            vocab.variants = derive_variants(llm, source, rows, vocab.canonical)
            save_vocab(vocab_path, vocab)
        if vocab.variants:
            print("  weak-variant spec for: %s"
                  % ", ".join(sorted(vocab.variants)))
        if editorial:
            print("  editorial: %d chars pinned into the prompt" % len(editorial))
        system = prompt_mod.build_system(name, meta, vocab.canonical, examples,
                                         vocab.variants, editorial)
        counters = {"done": 0, "cached": 0, "failed": 0}
        lock = threading.Lock()
        total = len(todo)

        groups = {}
        for row, code in todo:
            groups.setdefault(code_hash(code), []).append((row, code))
        print("  %d submissions to label, %d distinct sources"
              % (total, len(groups)))

        def work(digest, members):
            twin = store.get_by_hash(digest)
            if twin is not None and not args.force:
                return digest, members, (twin["algorithm"], twin["unoptimized"],
                                         twin.get("confidence", 0.0),
                                         twin.get("evidence", "")), True
            row, code = members[0]
            return digest, members, classify(llm, system, row, code), False

        with ThreadPoolExecutor(max_workers=args.workers) as pool:
            futures = [pool.submit(work, digest, members)
                       for digest, members in groups.items()]
            for future in as_completed(futures):
                try:
                    digest, members, payload, reused = future.result()
                except Exception as exc:
                    with lock:
                        counters["failed"] += 1
                    print("  failed: %s" % exc, file=sys.stderr)
                    continue
                algorithm, unoptimized, confidence, evidence = payload
                with lock:
                    canonical = vocab.resolve(
                        algorithm, learn=confidence >= args.min_confidence)
                label = normalize.compose(canonical, unoptimized)
                for row, _code in members:
                    store.put(_record(row, digest, canonical, unoptimized,
                                      confidence, label, llm.model, evidence))
                with lock:
                    counters["done"] += len(members)
                    counters["cached"] += len(members) - (0 if reused else 1)
                    if counters["done"] % 100 < len(members) or counters["done"] == total:
                        print("  %d/%d labelled (%d free from duplicate code, "
                              "%d failed)" % (counters["done"], total,
                                              counters["cached"], counters["failed"]))

        save_vocab(vocab_path, vocab)
        report_usage(llm)
        write_back(args, source, rows, store)
    finally:
        source.close()


def save_vocab(path, vocab):
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(vocab.to_dict(), fh, ensure_ascii=False, indent=2)


def report_usage(llm):
    usage = llm.usage.summary()
    if not usage["calls"]:
        return
    p_miss, p_hit, p_out = prices(llm.model)
    miss = max(0, usage["prompt_tokens"] - usage["cached_prompt_tokens"])
    cost = (miss * p_miss + usage["cached_prompt_tokens"] * p_hit
            + usage["completion_tokens"] * p_out) / 1e6
    print("  %d calls, %d prompt tokens (%d cached), %d output tokens, ~$%.2f"
          % (usage["calls"], usage["prompt_tokens"], usage["cached_prompt_tokens"],
             usage["completion_tokens"], cost))
    if usage["calls"]:
        per_row = cost / usage["calls"]
        print("  ~$%.4f per submission; ~$%.2f per 1000" % (per_row, per_row * 1000))


def write_back(args, source, rows, store):
    labels = store.labels()
    filled = added = 0
    for row in rows:
        label = labels.get(str(row["id"]))
        if label and (args.force or not row.get("label")):
            if not row.get("label"):
                added += 1
            row["label"] = label
        if row.get("label"):
            filled += 1

    if source.unpacked and not args.sidecar:
        target = os.path.join(source.dir, "%s.csv" % source.name)
    else:
        os.makedirs(args.out, exist_ok=True)
        target = os.path.join(args.out, "%s.csv" % source.name)

    tmp = target + ".tmp"
    with open(tmp, "w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(fh, fieldnames=source.fieldnames,
                                extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)
    os.replace(tmp, target)
    print("  wrote %d/%d labels (%d new this run) -> %s"
          % (filled, len(rows), added, target))


def evaluate(args, name):
    source = sources.ProblemSource(args.root, name)
    try:
        gold = {r["id"]: r["label"] for r in source.rows() if r.get("label")}
        announce_hand_labels(source)
    finally:
        source.close()
    store = ResultStore(os.path.join(args.out, "%s.jsonl" % name))
    held_out = load_example_ids(os.path.join(args.out, "%s.examples.json" % name))

    hits = both = algo_hits = flag_hits = 0
    over = under = unscoreable = 0
    misses = []
    for sid, label in gold.items():
        if str(sid) in held_out:
            continue
        record = store.get(sid)
        if record is None:
            continue
        gold_algo_raw, gold_unopt_raw = normalize.split(label)
        if gold_algo_raw and not _follows_convention(label, gold_algo_raw,
                                                     gold_unopt_raw):
            unscoreable += 1
            continue
        both += 1
        gold_algo, gold_unopt = normalize.split(label)
        same_algo = normalize.key(gold_algo) == normalize.key(record["algorithm"])
        algo_hits += same_algo
        flag_hits += gold_unopt == record["unoptimized"]
        if same_algo and gold_unopt == record["unoptimized"]:
            hits += 1
        else:
            if record["unoptimized"] and not gold_unopt:
                over += 1
            elif gold_unopt and not record["unoptimized"]:
                under += 1
            misses.append((sid, label, record["label"],
                           record.get("evidence", "")))
    if not both:
        print("%s: no overlap between hand labels and predictions" % name)
        return
    print("%s: %d hand-labelled rows predicted%s%s"
          % (name, both,
             ", %d held out as few-shots" % len(held_out) if held_out else "",
             ", %d skipped for using a label outside the convention" % unscoreable
             if unscoreable else ""))
    print("  algorithm only : %d/%d (%.1f%%)"
          % (algo_hits, both, 100.0 * algo_hits / both))
    print("  flag only      : %d/%d (%.1f%%)  [%d called weak wrongly, "
          "%d missed]" % (flag_hits, both, 100.0 * flag_hits / both, over, under))
    print("  algorithm+flag : %d/%d (%.1f%%)" % (hits, both, 100.0 * hits / both))
    for sid, want, got, why in misses[:25]:
        print("    %s  gold=%-28s pred=%-28s %s" % (sid, want, got, why[:60]))


def report(args, name):
    store = ResultStore(os.path.join(args.out, "%s.jsonl" % name))
    records = [r for r in store.by_id.values() if not r.get("error")]
    if not records:
        print("%s: nothing labelled yet" % name)
        return
    counts, shaky = {}, []
    for record in records:
        counts[record["label"]] = counts.get(record["label"], 0) + 1
        if record.get("confidence", 1.0) < args.min_confidence:
            shaky.append(record)
    print("%s: %d labelled, %d distinct labels" % (name, len(records), len(counts)))
    for label, count in sorted(counts.items(), key=lambda kv: -kv[1]):
        print("  %5d  %.1f%%  %s" % (count, 100.0 * count / len(records), label))
    rare = [l for l, c in counts.items() if c == 1]
    if rare:
        print("  singletons (possible stragglers): %s" % ", ".join(sorted(rare)[:15]))
    if shaky:
        print("  %d below confidence %.2f, e.g. %s" % (
            len(shaky), args.min_confidence,
            ", ".join(r["id"] for r in shaky[:10])))


def estimate(args, names):
    total_rows = total_chars = prefix_tokens = 0
    for name in names:
        source = sources.ProblemSource(args.root, name)
        try:
            rows = source.rows()
            sample = rows[:args.sample] or rows
            chars = sum(len(source.code(r["id"]) or "") for r in sample)
            per_row = chars / max(1, len(sample))
            vocab_path = os.path.join(args.out, "%s.vocab.json" % name)
            vocab = normalize.Vocabulary()
            if os.path.isfile(vocab_path):
                vocab = normalize.Vocabulary.from_dict(json.load(open(vocab_path)))
            examples = pick_examples(source, rows, args.examples)[0]
            system = prompt_mod.build_system(
                name, source.meta(), vocab.canonical, examples,
                vocab.variants if args.variants else None,
                source.solution() if args.editorial else None)
            per_prefix = len(system) / 3.3
            prefix_tokens += per_prefix * len(rows)
            total_rows += len(rows)
            total_chars += per_row * len(rows)
            print("%-16s %5d rows, mean %5.0f code chars, %5.0f prefix tokens"
                  % (name, len(rows), per_row, per_prefix))
        finally:
            source.close()
    p_miss, p_hit, p_out = prices(args.model)
    thinks = client_mod.is_reasoning(args.model) and args.thinking != "off"
    out_per_row = 1500 if thinks else 50
    code_tokens = total_chars / 3.3
    cost = (code_tokens * p_miss + prefix_tokens * p_hit
            + out_per_row * total_rows * p_out) / 1e6
    print("\n%d submissions, ~%.1fM code tokens + ~%.1fM cached prefix tokens"
          % (total_rows, code_tokens / 1e6, prefix_tokens / 1e6))
    print("estimated ~$%.2f at list price (~$%.2f off-peak)" % (cost, cost / 2))


def main(argv=None):
    parser = argparse.ArgumentParser(description="Label every infoarena submission with the algorithm it implements.")
    parser.add_argument("problems", nargs="*",
                        help="problem names; default is every problem found")
    parser.add_argument("--root", default=DEFAULT_ROOT)
    parser.add_argument("--out", default=DEFAULT_OUT,
                        help="where caches, vocabularies and sidecar csvs go")
    parser.add_argument("--model", default=client_mod.DEFAULT_MODEL)
    parser.add_argument("--base-url", default=None)
    parser.add_argument("--temperature", type=float, default=0.0,
                        help="ignored for reasoning models")
    parser.add_argument("--max-tokens", type=int, default=0,
                        help="completion budget; defaults to 200, or 8192 when "
                             "the model name looks like a reasoning model")
    parser.add_argument("--thinking", choices=client_mod.THINKING_MODES,
                        default="auto",
                        help="'off' tells a v4 model to answer without thinking, "
                             "which cuts output tokens (and cost) by ~200x; 'auto' "
                             "leaves the model's own default alone")
    parser.add_argument("--reasoning-effort", choices=client_mod.REASONING_EFFORTS,
                        default="auto",
                        help="how hard a thinking model deliberates; 'minimal' "
                             "cuts hidden tokens ~5x. Ignored with --thinking off")
    parser.add_argument("--workers", type=int, default=8)
    parser.add_argument("--min-confidence", type=float, default=0.4,
                        help="below this, an answer cannot create a new label")
    parser.add_argument("--no-variants", dest="variants", action="store_false",
                        help="skip the label-derived standard/weak spec; use to "
                             "measure what a problem with no hand labels gets")
    parser.add_argument("--no-editorial", dest="editorial", action="store_false",
                        help="do not pin solution.txt into the system message")
    parser.add_argument("--examples", type=int, default=6,
                        help="hand-labelled submissions pinned into the system "
                             "message as few-shots; they anchor the unoptimized "
                             "flag, and --eval holds them out")
    parser.add_argument("--sample", type=int, default=60,
                        help="submissions classified in the discovery pass")
    parser.add_argument("--limit", type=int, default=0,
                        help="consider at most N unlabelled rows per problem; "
                             "rows whose source was never scraped still count")
    parser.add_argument("--force", action="store_true",
                        help="re-label rows that are already cached or labelled")
    parser.add_argument("--rediscover", action="store_true",
                        help="rebuild the vocabulary even if one is cached")
    parser.add_argument("--sidecar", action="store_true",
                        help="never touch the original csv; write to --out instead")
    parser.add_argument("--mock", action="store_true",
                        help="offline keyword classifier, no API calls")
    parser.add_argument("--eval", action="store_true",
                        help="score cached predictions against hand-written labels")
    parser.add_argument("--estimate", action="store_true",
                        help="print a token/cost estimate and exit")
    parser.add_argument("--report", action="store_true",
                        help="summarise cached labels and flag shaky ones")
    args = parser.parse_args(argv)

    names = args.problems or sources.discover(args.root)
    if args.estimate:
        estimate(args, names)
        return 0
    for name in names:
        if args.report:
            report(args, name)
        elif args.eval:
            evaluate(args, name)
        else:
            label_problem(args, name)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
