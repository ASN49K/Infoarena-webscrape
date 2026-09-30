#!/usr/bin/env python3

import argparse
import csv
import io
import os
import shutil
import sys
import tempfile
import zipfile

from split_solutions import (DirProblem, ZipProblem, collect_problems,
                             _copy_member)

LANG_DIRS = {"cpp": "cpp_sol", "c": "c_sol", "java": "java_sol",
             "pas": "pas_sol", "py": "py_sol", "rs": "rs_sol"}

EXT_LANG = {
    ".cpp": "cpp", ".cc": "cpp", ".cxx": "cpp", ".c++": "cpp",
    ".c": "c",
    ".java": "java",
    ".pas": "pas", ".p": "pas",
    ".py": "py",
    ".rs": "rs",
}

UNKNOWN_DIR = "unknown_sol"


def lang_of(filename):
    return EXT_LANG.get(os.path.splitext(filename)[1].lower())


def listing(problem, folder):
    if problem.is_zip:
        prefix = f"{problem.name}/{folder}/"
        return [n[len(prefix):] for n in problem.names
                if n.startswith(prefix) and not n.endswith("/")
                and "/" not in n[len(prefix):]]
    d = os.path.join(problem.path, folder)
    if not os.path.isdir(d):
        return []
    return [e.name for e in os.scandir(d) if e.is_file()]


def language_map(problem):
    langs = {}
    for name in listing(problem, "solutions"):
        lang = lang_of(name)
        if lang is not None:
            langs[os.path.splitext(name)[0]] = lang
    for lang, folder in LANG_DIRS.items():
        for name in listing(problem, folder):
            if name.lower().endswith(".csv"):
                continue
            langs.setdefault(os.path.splitext(name)[0], lang_of(name) or lang)
    return langs


def split_rows(text, langs, keep_unknown, terminator="\r\n"):
    stats = {"rows": 0, "sources": len(langs), "no_id_column": False,
             "nolang": 0}
    stats.update({lang: 0 for lang in LANG_DIRS})

    rows = list(csv.reader(io.StringIO(text)))
    if not rows:
        stats["no_id_column"] = True
        return {}, stats
    header = rows[0]
    try:
        id_col = header.index("id")
    except ValueError:
        stats["no_id_column"] = True
        return {}, stats

    buckets = {}
    for row in rows[1:]:
        if not row:
            continue
        stats["rows"] += 1
        sid = row[id_col].strip() if id_col < len(row) else ""
        lang = langs.get(sid)
        if lang is None or lang not in LANG_DIRS:
            stats["nolang"] += 1
            if not keep_unknown:
                continue
            folder = UNKNOWN_DIR
        else:
            stats[lang] += 1
            folder = LANG_DIRS[lang]
        buckets.setdefault(folder, []).append(row)

    out = {}
    for folder, kept in buckets.items():
        buf = io.StringIO()
        writer = csv.writer(buf, lineterminator=terminator)
        writer.writerow(header)
        writer.writerows(kept)
        out[folder] = buf.getvalue()
    return out, stats


def plan(problem, wanted, keep_unknown):
    text = problem.csv_text()
    if text is None:
        return {}, {"rows": 0, "sources": 0, "no_csv": True,
                    "no_id_column": False, "nolang": 0,
                    **{lang: 0 for lang in LANG_DIRS}}
    buckets, stats = split_rows(text, language_map(problem), keep_unknown)
    stats["no_csv"] = False
    keep = {f"{folder}/{problem.name}.csv": body
            for folder, body in buckets.items()
            if folder == UNKNOWN_DIR or folder in wanted}
    return keep, stats


def write_files(root, keep, dry_run):
    for rel, body in sorted(keep.items()):
        if dry_run:
            continue
        dest = os.path.join(root, rel)
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        with open(dest, "w", encoding="utf-8", newline="") as f:
            f.write(body)


def write_zip_in_place(problem, keep, dry_run):
    if dry_run or not keep:
        return
    replaced = {f"{problem.name}/{rel}" for rel in keep}
    tmp_fd, tmp_path = tempfile.mkstemp(
        dir=os.path.dirname(os.path.abspath(problem.path)),
        prefix=f".{os.path.basename(problem.path)}.", suffix=".tmp")
    os.close(tmp_fd)
    try:
        with zipfile.ZipFile(problem.path) as zin, \
                zipfile.ZipFile(tmp_path, "w", zipfile.ZIP_DEFLATED) as zout:
            for info in zin.infolist():
                if info.filename in replaced:
                    continue
                _copy_member(zin, zout, info, info.filename)
            written = {i.filename for i in zout.infolist()}
            for rel, body in sorted(keep.items()):
                folder = f"{problem.name}/{rel.split('/')[0]}/"
                if folder not in written:
                    zout.writestr(zipfile.ZipInfo(folder), b"")
                    written.add(folder)
                zout.writestr(f"{problem.name}/{rel}",
                              body.encode("utf-8"))
        shutil.copystat(problem.path, tmp_path)
        os.replace(tmp_path, problem.path)
    finally:
        if os.path.exists(tmp_path):
            os.remove(tmp_path)


def loose_csv(path, base, out, wanted, keep_unknown, dry_run):
    with open(path, encoding="utf-8", errors="replace", newline="") as f:
        text = f.read()
    stem = os.path.splitext(os.path.basename(path))[0]

    rows = list(csv.reader(io.StringIO(text)))
    slug = stem
    if rows and "problem" in rows[0]:
        col = rows[0].index("problem")
        named = {r[col].strip() for r in rows[1:] if len(r) > col and r[col].strip()}
        if len(named) == 1:
            slug = named.pop()

    problems = {p.name: p for p in collect_problems(base)} if os.path.isdir(base) else {}
    problem = problems.get(slug)
    if problem is None:
        print(f"error: no problem '{slug}' under '{base}' to read languages from",
              file=sys.stderr)
        return None
    try:
        buckets, stats = split_rows(text, language_map(problem), keep_unknown,
                                    "\n" if "\r\n" not in text else "\r\n")
    finally:
        problem.close()

    keep = {f"{folder}/{stem}.csv": body for folder, body in buckets.items()
            if folder == UNKNOWN_DIR or folder in wanted}
    root = out or os.path.join(os.path.dirname(os.path.abspath(path)),
                               f"{stem}_by_lang")
    write_files(root, keep, dry_run)
    stats["problem"] = stem
    stats["no_csv"] = False
    if not dry_run:
        print(f"\nSplit written to {os.path.normpath(root)}/<lang>_sol/{stem}.csv")
    return stats


def report(all_stats, out_note):
    wname = max([len("problem")] + [len(s["problem"]) for s in all_stats])
    cols = list(LANG_DIRS) + ["nolang"]
    header = (f"{'problem':<{wname}}  {'rows':>7}  {'sources':>7}  "
              + "  ".join(f"{c:>7}" for c in cols))
    print()
    print(header)
    print("-" * len(header))
    for s in all_stats:
        print(f"{s['problem']:<{wname}}  {s['rows']:>7}  {s['sources']:>7}  "
              + "  ".join(f"{s[c]:>7}" for c in cols))
    print("-" * len(header))
    totals = {k: sum(s[k] for s in all_stats)
              for k in ["rows", "sources"] + cols}
    print(f"{'TOTAL':<{wname}}  {totals['rows']:>7}  {totals['sources']:>7}  "
          + "  ".join(f"{totals[c]:>7}" for c in cols)
          + f"    ({len(all_stats)} problems)")
    if out_note:
        print(out_note)


def main():
    ap = argparse.ArgumentParser(
        description="Split each <problem>.csv into one CSV per language, stored "
                    "in the <lang>_sol/ folder holding that language's sources.")
    ap.add_argument("base", nargs="?", default="infoarena",
                    help="the collection directory (default: infoarena)")
    ap.add_argument("-o", "--out", metavar="DIR",
                    help="write the split into DIR/<problem>/<lang>_sol/ instead "
                         "of into each problem")
    ap.add_argument("--csv", metavar="FILE",
                    help="split this single CSV instead of the collection; its "
                         "languages come from the problem of the same name "
                         "under the collection directory")
    ap.add_argument("--only", nargs="+", metavar="SLUG",
                    help="split only these problems")
    ap.add_argument("--langs", default=",".join(LANG_DIRS),
                    help=f"comma-separated subset of {','.join(LANG_DIRS)} "
                         f"(default: all)")
    ap.add_argument("--in-zip", action="store_true",
                    help="also write into problems stored as archives, which "
                         "rewrites each one whole (default: skip them)")
    ap.add_argument("--keep-unknown", action="store_true",
                    help=f"write rows with no saved source to "
                         f"{UNKNOWN_DIR}/<problem>.csv (default: drop them)")
    ap.add_argument("--dry-run", action="store_true",
                    help="report what would happen, write nothing")
    args = ap.parse_args()

    langs = [l.strip().lower() for l in args.langs.split(",") if l.strip()]
    unknown = [l for l in langs if l not in LANG_DIRS]
    if unknown or not langs:
        print(f"error: --langs must be a subset of {','.join(LANG_DIRS)}"
              f"{f' (got {unknown})' if unknown else ''}", file=sys.stderr)
        return 1
    wanted = {LANG_DIRS[l] for l in langs}

    if args.dry_run:
        print("(dry run: nothing is written)", file=sys.stderr)

    if args.csv:
        if not os.path.isfile(args.csv):
            print(f"error: '{args.csv}' is not a file", file=sys.stderr)
            return 1
        stats = loose_csv(args.csv, args.base, args.out, wanted,
                          args.keep_unknown, args.dry_run)
        if stats is None:
            return 1
        report([stats], None)
        return 0

    if not os.path.isdir(args.base):
        print(f"error: '{args.base}' is not a directory", file=sys.stderr)
        return 1

    problems = collect_problems(args.base)
    if args.only:
        missing = set(args.only) - {p.name for p in problems}
        if missing:
            print(f"warning: not found under '{args.base}': {sorted(missing)}",
                  file=sys.stderr)
        problems = [p for p in problems if p.name in set(args.only)]
    if not problems:
        print(f"No problems found under '{args.base}/'.", file=sys.stderr)
        return 1

    all_stats, failed, wrote = [], [], False
    for i, problem in enumerate(problems, 1):
        print(f"[{i}/{len(problems)}] {problem.name}"
              f"{' (zip)' if problem.is_zip else ''}", file=sys.stderr)
        try:
            keep, stats = plan(problem, wanted, args.keep_unknown)
            if stats["no_csv"]:
                print("    ! no readable <problem>.csv, skipped", file=sys.stderr)
            elif stats["no_id_column"]:
                print("    ! <problem>.csv has no id column, skipped",
                      file=sys.stderr)
            elif args.out:
                write_files(os.path.join(args.out, problem.name), keep,
                            args.dry_run)
                wrote = wrote or bool(keep)
            elif problem.is_zip and not args.in_zip:
                print("    - archive, skipped (--in-zip writes into it, -o "
                      "writes elsewhere)", file=sys.stderr)
            elif problem.is_zip:
                write_zip_in_place(problem, keep, args.dry_run)
                wrote = wrote or bool(keep)
            else:
                write_files(problem.path, keep, args.dry_run)
                wrote = wrote or bool(keep)
            if not stats["no_csv"] and not stats["sources"]:
                print("    ! no saved sources to read languages from, every "
                      "row counted as nolang", file=sys.stderr)
        except (OSError, csv.Error, zipfile.BadZipFile) as e:
            print(f"    ! {problem.name}: {e}", file=sys.stderr)
            failed.append(problem.name)
            continue
        finally:
            problem.close()
        stats["problem"] = problem.name
        all_stats.append(stats)

    if not all_stats:
        print("Nothing to split.", file=sys.stderr)
        return 1 if failed else 0
    where = args.out if args.out else os.path.normpath(args.base)
    note = (None if args.dry_run or not wrote else
            f"\nSplit written to {where}/<problem>/"
            f"{{{','.join(LANG_DIRS[l] for l in langs)}}}/<problem>.csv")
    report(all_stats, note)
    if failed:
        print(f"failed: {failed}", file=sys.stderr)
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
