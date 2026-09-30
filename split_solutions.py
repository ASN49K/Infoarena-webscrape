#!/usr/bin/env python3

import argparse
import csv
import io
import os
import re
import shutil
import sys
import tempfile
import zipfile

LANG_DIRS = {"cpp": "cpp_sol", "c": "c_sol", "java": "java_sol"}

EXT_LANG = {
    ".cpp": "cpp", ".cc": "cpp", ".cxx": "cpp", ".c++": "cpp",
    ".c": "c",
    ".java": "java",
}

REJECT_TOKENS = (b"__attribute__", b"__restrict")

FINAL_RE = re.compile(rb"\bfinal\b")


def lang_of(filename):
    return EXT_LANG.get(os.path.splitext(filename)[1].lower())


def scoring_ids(text):
    rows = csv.DictReader(io.StringIO(text))
    if not rows.fieldnames or "id" not in rows.fieldnames:
        return None, None
    every, scored = set(), set()
    for r in rows:
        sid = (r.get("id") or "").strip()
        if not sid:
            continue
        every.add(sid)
        try:
            if float((r.get("score") or "0").strip() or "0") != 0:
                scored.add(sid)
        except ValueError:
            pass
    return every, scored


def reject_reason(data):
    if any(tok in data for tok in REJECT_TOKENS):
        return "gcc_ext"
    if FINAL_RE.search(data):
        return "has_final"
    return None


class DirProblem:
    def __init__(self, path):
        self.path = os.path.normpath(path)
        self.name = os.path.basename(self.path)
        self.is_zip = False

    def csv_text(self):
        for cand in self._csv_candidates():
            try:
                with open(os.path.join(self.path, cand), encoding="utf-8",
                          errors="replace") as f:
                    return f.read()
            except OSError:
                continue
        return None

    def _csv_candidates(self):
        preferred = f"{self.name}.csv"
        names = sorted(e.name for e in os.scandir(self.path)
                       if e.is_file() and e.name.endswith(".csv"))
        if preferred in names:
            names.remove(preferred)
            names.insert(0, preferred)
        return names

    def solutions(self):
        d = os.path.join(self.path, "solutions")
        if not os.path.isdir(d):
            return []
        return sorted((e.name, e.path) for e in os.scandir(d) if e.is_file())

    def read_solution(self, ref):
        with open(ref, "rb") as f:
            return f.read()

    def close(self):
        pass


class ZipProblem:
    def __init__(self, path):
        self.path = path
        self.is_zip = True
        self._zf = None
        with zipfile.ZipFile(path) as z:
            self.names = z.namelist()
        tops = {n.split("/", 1)[0] for n in self.names if n}
        self.name = tops.pop() if len(tops) == 1 else os.path.basename(path)[:-4]

    def csv_text(self):
        prefix = f"{self.name}/"
        top = [n for n in self.names
               if n.startswith(prefix) and n.endswith(".csv")
               and "/" not in n[len(prefix):]]
        preferred = f"{prefix}{self.name}.csv"
        for member in ([preferred] if preferred in top else []) + sorted(top):
            try:
                with zipfile.ZipFile(self.path) as z, z.open(member) as f:
                    return f.read().decode("utf-8", "replace")
            except (KeyError, OSError, zipfile.BadZipFile):
                continue
        return None

    def solutions(self):
        prefix = f"{self.name}/solutions/"
        out = []
        for n in self.names:
            if n.startswith(prefix) and not n.endswith("/"):
                rest = n[len(prefix):]
                if "/" not in rest:
                    out.append((rest, n))
        return sorted(out)

    def read_solution(self, ref):
        if self._zf is None:
            self._zf = zipfile.ZipFile(self.path)
        with self._zf.open(ref) as f:
            return f.read()

    def close(self):
        if self._zf is not None:
            self._zf.close()
            self._zf = None


def collect_problems(base):
    problems = {}
    for e in sorted(os.scandir(base), key=lambda e: e.name):
        if e.is_dir():
            problems[e.name] = DirProblem(e.path)
    for e in sorted(os.scandir(base), key=lambda e: e.name):
        if e.is_file() and e.name.endswith(".zip"):
            stem = e.name[:-4]
            if stem not in problems:
                try:
                    problems[stem] = ZipProblem(e.path)
                except zipfile.BadZipFile:
                    print(f"warning: skipping unreadable archive '{e.path}'",
                          file=sys.stderr)
    return [problems[k] for k in sorted(problems)]


def plan(problem, langs):
    stats = {"csv_rows": 0, "solutions": 0, "no_csv": False, "other_lang": 0,
             "not_in_csv": 0, "zero_score": 0, "gcc_ext": 0, "has_final": 0}
    stats.update({lang: 0 for lang in LANG_DIRS})

    text = problem.csv_text()
    every, scored = scoring_ids(text) if text is not None else (None, None)
    if every is None:
        stats["no_csv"] = True
        return {}, stats
    stats["csv_rows"] = len(scored)

    keep = {}
    for name, ref in problem.solutions():
        stats["solutions"] += 1
        lang = lang_of(name)
        if lang is None or lang not in langs:
            stats["other_lang"] += 1
            continue
        sid = os.path.splitext(name)[0]
        if sid not in every:
            stats["not_in_csv"] += 1
            continue
        if sid not in scored:
            stats["zero_score"] += 1
            continue
        data = problem.read_solution(ref)
        reason = reject_reason(data)
        if reason is not None:
            stats[reason] += 1
            continue
        keep[name] = (f"{LANG_DIRS[lang]}/{name}", data)
        stats[lang] += 1
    return keep, stats


def write_out_tree(problem, keep, out_base, dry_run):
    _write_files(os.path.join(out_base, problem.name), keep, dry_run)


def split_dir_in_place(problem, keep, keep_solutions, dry_run):
    _write_files(problem.path, keep, dry_run)
    src_dir = os.path.join(problem.path, "solutions")
    if not dry_run and not keep_solutions and os.path.isdir(src_dir):
        shutil.rmtree(src_dir)


def _write_files(root, keep, dry_run):
    for _name, (rel, data) in sorted(keep.items()):
        if dry_run:
            continue
        dest = os.path.join(root, rel)
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        with open(dest, "wb") as f:
            f.write(data)


def zip_dir(root):
    root = os.path.normpath(root)
    if os.path.exists(root + ".zip"):
        return None
    parent = os.path.dirname(root) or "."
    archive = shutil.make_archive(root, "zip", root_dir=parent,
                                  base_dir=os.path.basename(root))
    shutil.rmtree(root)
    return archive


def split_zip_in_place(problem, keep, keep_solutions, dry_run):
    prefix = f"{problem.name}/solutions/"
    if dry_run or not any(n.startswith(prefix) for n in problem.names):
        return
    lang_prefixes = tuple(f"{problem.name}/{d}/" for d in LANG_DIRS.values())
    tmp_fd, tmp_path = tempfile.mkstemp(
        dir=os.path.dirname(os.path.abspath(problem.path)),
        prefix=f".{os.path.basename(problem.path)}.", suffix=".tmp")
    os.close(tmp_fd)
    try:
        with zipfile.ZipFile(problem.path) as zin, \
                zipfile.ZipFile(tmp_path, "w", zipfile.ZIP_DEFLATED) as zout:
            for info in zin.infolist():
                name = info.filename
                if name.startswith(lang_prefixes):
                    continue
                if name.startswith(prefix):
                    rest = name[len(prefix):]
                    if not rest or "/" in rest or rest not in keep:
                        if not keep_solutions:
                            continue
                    else:
                        rel, data = keep[rest]
                        new = zipfile.ZipInfo(f"{problem.name}/{rel}",
                                              date_time=info.date_time)
                        new.compress_type = info.compress_type
                        new.external_attr = info.external_attr
                        zout.writestr(new, data)
                        if not keep_solutions:
                            continue
                _copy_member(zin, zout, info, name)
            for rel, _data in sorted(keep.values()):
                folder = f"{problem.name}/{rel.split('/')[0]}/"
                if folder not in {i.filename for i in zout.infolist()}:
                    zout.writestr(zipfile.ZipInfo(folder), b"")
        shutil.copystat(problem.path, tmp_path)
        os.replace(tmp_path, problem.path)
    finally:
        if os.path.exists(tmp_path):
            os.remove(tmp_path)


def _copy_member(zin, zout, info, new_name):
    new = zipfile.ZipInfo(new_name, date_time=info.date_time)
    new.compress_type = info.compress_type
    new.external_attr = info.external_attr
    new.internal_attr = info.internal_attr
    new.create_system = info.create_system
    if new_name.endswith("/"):
        zout.writestr(new, b"")
        return
    with zin.open(info) as src, zout.open(new, "w") as dst:
        shutil.copyfileobj(src, dst, 1024 * 1024)


def main():
    ap = argparse.ArgumentParser(
        description="Split solutions/ into cpp_sol/, c_sol/ and java_sol/, "
                    "keeping only the submissions listed in <problem>.csv.")
    ap.add_argument("base", nargs="?", default="infoarena",
                    help="the collection directory (default: infoarena)")
    ap.add_argument("-o", "--out", metavar="DIR",
                    help="copy the kept sources into DIR/<problem>/<lang>_sol/ "
                         "instead of splitting each problem in place")
    ap.add_argument("--only", nargs="+", metavar="SLUG",
                    help="split only these problems")
    ap.add_argument("--langs", default=",".join(LANG_DIRS),
                    help=f"comma-separated subset of {','.join(LANG_DIRS)} "
                         f"(default: all)")
    ap.add_argument("--no-zip", action="store_true",
                    help="leave a split problem as a plain directory instead of "
                         "compressing it back to <problem>.zip")
    ap.add_argument("--drop-solutions", action="store_true",
                    help="delete the original solutions/ folder once the kept "
                         "sources have been split out of it (default: keep it)")
    ap.add_argument("--dry-run", action="store_true",
                    help="report what would happen, write nothing")
    args = ap.parse_args()

    if not os.path.isdir(args.base):
        print(f"error: '{args.base}' is not a directory", file=sys.stderr)
        return 1

    langs = [l.strip().lower() for l in args.langs.split(",") if l.strip()]
    unknown = [l for l in langs if l not in LANG_DIRS]
    if unknown or not langs:
        print(f"error: --langs must be a subset of {','.join(LANG_DIRS)}"
              f"{f' (got {unknown})' if unknown else ''}", file=sys.stderr)
        return 1

    problems = collect_problems(args.base)
    if args.only:
        wanted = set(args.only)
        missing = wanted - {p.name for p in problems}
        if missing:
            print(f"warning: not found under '{args.base}': {sorted(missing)}",
                  file=sys.stderr)
        problems = [p for p in problems if p.name in wanted]
    if not problems:
        print(f"No problems found under '{args.base}/'.", file=sys.stderr)
        return 1

    if args.dry_run:
        print("(dry run: nothing is written)", file=sys.stderr)

    all_stats, failed = [], []
    for i, problem in enumerate(problems, 1):
        print(f"[{i}/{len(problems)}] {problem.name}"
              f"{' (zip)' if problem.is_zip else ''}", file=sys.stderr)
        try:
            target = None
            keep, stats = plan(problem, langs)
            if stats["no_csv"]:
                print(f"    ! no readable <problem>.csv, skipped", file=sys.stderr)
            elif args.out:
                write_out_tree(problem, keep, args.out, args.dry_run)
                target = os.path.join(args.out, problem.name)
            elif problem.is_zip:
                split_zip_in_place(problem, keep, not args.drop_solutions,
                                   args.dry_run)
            else:
                split_dir_in_place(problem, keep, not args.drop_solutions,
                                   args.dry_run)
                target = problem.path
            if target and not args.no_zip and not args.dry_run \
                    and os.path.isdir(target):
                archive = zip_dir(target)
                if archive:
                    print(f"    zipped -> {archive} (folder removed)",
                          file=sys.stderr)
                else:
                    print(f"    ! {target}.zip already exists, left "
                          f"{target}/ uncompressed", file=sys.stderr)
        except (OSError, zipfile.BadZipFile) as e:
            print(f"    ! {problem.name}: {e}", file=sys.stderr)
            failed.append(problem.name)
            continue
        finally:
            problem.close()
        stats["problem"] = problem.name
        all_stats.append(stats)

    dropped = [("notinCSV", "not_in_csv"), ("score0", "zero_score"),
               ("gccext", "gcc_ext"), ("final", "has_final"),
               ("otherlang", "other_lang")]
    wname = max([len("problem")] + [len(s["problem"]) for s in all_stats])
    header = (f"{'problem':<{wname}}  {'scored':>7}  {'sources':>7}  "
              + "  ".join(f"{c:>7}" for c in LANG_DIRS)
              + "  " + "  ".join(f"{h:>9}" for h, _ in dropped))
    print()
    print(header)
    print("-" * len(header))
    for s in all_stats:
        print(f"{s['problem']:<{wname}}  {s['csv_rows']:>7}  {s['solutions']:>7}  "
              + "  ".join(f"{s[l]:>7}" for l in LANG_DIRS)
              + "  " + "  ".join(f"{s[k]:>9}" for _, k in dropped))
    print("-" * len(header))
    totals = {k: sum(s[k] for s in all_stats)
              for k in ["csv_rows", "solutions"]
              + list(LANG_DIRS) + [k for _, k in dropped]}
    print(f"{'TOTAL':<{wname}}  {totals['csv_rows']:>7}  {totals['solutions']:>7}  "
          + "  ".join(f"{totals[l]:>7}" for l in LANG_DIRS)
          + "  " + "  ".join(f"{totals[k]:>9}" for _, k in dropped)
          + f"    ({len(all_stats)} problems)")
    if not args.dry_run:
        where = args.out if args.out else os.path.normpath(args.base)
        print(f"\nSplit written to {where}/<problem>/"
              f"{{{','.join(LANG_DIRS[l] for l in langs)}}}/")
    if failed:
        print(f"failed: {failed}", file=sys.stderr)
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
