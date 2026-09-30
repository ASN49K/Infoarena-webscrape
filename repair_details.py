#!/usr/bin/env python3

import argparse
import csv
import io
import json
import os
import re
import shutil
import sys
import tempfile
import zipfile

FIELDS = ["submission_id", "test", "subtask", "time", "memory", "message",
          "ok", "test_points", "subtask_points"]

WORD_CORECT = re.compile(r"\bcorect\b")


def mislabelled(message):
    m = (message or "").strip().lower()
    return "corect" in m and not WORD_CORECT.search(m)


def repair_rows(rows, grouped):
    fixed = filled = 0
    out = []
    for r in rows:
        ok = r.get("ok", "")
        if ok == "YES" and mislabelled(r.get("message")):
            ok = "NO"
            fixed += 1
        points = r.get("test_points")
        if points is None:
            points = "" if grouped else r.get("subtask_points", "")
            if points != "":
                filled += 1
        new = {f: r.get(f, "") for f in FIELDS}
        new["ok"] = ok
        new["test_points"] = points
        out.append(new)
    return out, fixed, filled


def render_csv(rows):
    buf = io.StringIO()
    w = csv.DictWriter(buf, fieldnames=FIELDS, lineterminator="\r\n")
    w.writeheader()
    w.writerows(rows)
    return buf.getvalue().encode("utf-8")


def read_rows(raw):
    return list(csv.DictReader(io.StringIO(raw.decode("utf-8", "replace"))))


def problem_is_grouped(zf, detail_names):
    for n in detail_names:
        subtasks = [r.get("subtask") for r in read_rows(zf.read(n))]
        if len(subtasks) != len(set(subtasks)):
            return True
    return False


def repair_json_tests(data, grouped):
    tests = data.get("tests")
    if not isinstance(tests, list):
        return False, 0, 0
    fixed = filled = added = 0
    out = []
    for t in tests:
        if not isinstance(t, dict):
            out.append(t)
            continue
        t = dict(t)
        if t.get("ok") is True and mislabelled(t.get("message")):
            t["ok"] = False
            fixed += 1
        if "test_points" not in t:
            added += 1
            if grouped:
                t["test_points"] = None
            else:
                t["test_points"] = t.get("subtask_points")
                filled += 1
        out.append({k: t[k] for k in
                    ("test", "subtask", "time", "memory", "message", "ok",
                     "test_points", "subtask_points") if k in t}
                   | {k: v for k, v in t.items() if k not in FIELDS})
    data["tests"] = out
    return (fixed + added) > 0, fixed, filled


def rewrite_zip(path, replacements):
    fd, tmp = tempfile.mkstemp(dir=os.path.dirname(path) or ".", suffix=".zip")
    os.close(fd)
    try:
        with zipfile.ZipFile(path) as src, \
                zipfile.ZipFile(tmp, "w", zipfile.ZIP_DEFLATED) as dst:
            for info in src.infolist():
                data = replacements.get(info.filename)
                dst.writestr(info, src.read(info.filename) if data is None else data)
        shutil.copystat(path, tmp)
        os.replace(tmp, path)
    except BaseException:
        if os.path.exists(tmp):
            os.unlink(tmp)
        raise


def repair_problem(path, opts):
    name = os.path.basename(path)[:-4]
    stats = {"ok_fixed": 0, "points_filled": 0, "csv": 0, "json": 0,
             "grouped": False}
    with zipfile.ZipFile(path) as zf:
        names = zf.namelist()
        details = [n for n in names if "/details/" in n and n.endswith(".csv")]
        subs = [n for n in names if "/submissions/" in n and n.endswith(".json")]
        if not details:
            print(f"  {name}: no details/ to repair", file=sys.stderr)
            return stats

        grouped = problem_is_grouped(zf, details)
        stats["grouped"] = grouped
        replacements = {}

        for n in details:
            rows = read_rows(zf.read(n))
            new, fixed, filled = repair_rows(rows, grouped)
            raw = render_csv(new)
            if raw != zf.read(n):
                replacements[n] = raw
                stats["csv"] += 1
                stats["ok_fixed"] += fixed
                stats["points_filled"] += filled

        if not opts["no_json"]:
            for n in subs:
                try:
                    data = json.loads(zf.read(n).decode("utf-8", "replace"))
                except ValueError:
                    continue
                changed, fixed, filled = repair_json_tests(data, grouped)
                if changed:
                    replacements[n] = json.dumps(
                        data, ensure_ascii=False, indent=2).encode("utf-8")
                    stats["json"] += 1

    kind = "grouped" if grouped else "per-test"
    if not replacements:
        print(f"  {name:14s} ({kind:8s}) already repaired", file=sys.stderr)
        return stats
    if not opts["dry_run"]:
        rewrite_zip(path, replacements)
    print(f"  {name:14s} ({kind:8s}) {stats['ok_fixed']:6d} ok fixed, "
          f"{stats['points_filled']:6d} test_points filled, "
          f"{stats['csv']} csv + {stats['json']} json rewritten", file=sys.stderr)
    return stats


def main():
    ap = argparse.ArgumentParser(
        description="Fix the ok column and backfill test_points in the "
                    "archive's already-scraped per-test reports.")
    ap.add_argument("problem", nargs="*",
                    help="problem slug(s); omit to repair every <base-dir>/*.zip")
    ap.add_argument("--base-dir", default="infoarena",
                    help="directory holding <problem>.zip (default: infoarena)")
    ap.add_argument("--no-json", action="store_true",
                    help="repair details/ only, leaving the copies inside "
                         "submissions/*.json untouched")
    ap.add_argument("--dry-run", action="store_true",
                    help="report what would change without writing")
    args = ap.parse_args()

    if not os.path.isdir(args.base_dir):
        sys.exit(f"error: no such directory: {args.base_dir}")
    problems = args.problem or sorted(
        os.path.splitext(f)[0] for f in os.listdir(args.base_dir)
        if f.lower().endswith(".zip"))
    if not problems:
        sys.exit(f"error: no problem archives found in {args.base_dir}/")

    opts = {"no_json": args.no_json, "dry_run": args.dry_run}
    print(f"=== repairing {len(problems)} problem(s)"
          f"{' (dry run)' if args.dry_run else ''} ===", file=sys.stderr)

    total = {"ok_fixed": 0, "points_filled": 0, "csv": 0, "json": 0}
    grouped_problems = []
    failed = []
    for slug in problems:
        path = os.path.join(args.base_dir, slug + ".zip")
        if not os.path.exists(path):
            print(f"  error: no such archive: {path}", file=sys.stderr)
            failed.append(slug)
            continue
        try:
            s = repair_problem(path, opts)
        except Exception as exc:
            print(f"  ! {slug}: {type(exc).__name__}: {exc}", file=sys.stderr)
            failed.append(slug)
            continue
        for k in total:
            total[k] += s[k]
        if s["grouped"]:
            grouped_problems.append(slug)

    print(f"\n=== {total['ok_fixed']} ok values fixed, "
          f"{total['points_filled']} test_points filled; "
          f"{total['csv']} CSV + {total['json']} JSON rewritten ===",
          file=sys.stderr)
    if grouped_problems:
        print(f"    {len(grouped_problems)} grouped problem(s) have test_points "
              f"left empty (not derivable; re-scrape to fill):\n"
              f"    {' '.join(grouped_problems)}", file=sys.stderr)
    if args.dry_run:
        print("    dry run: nothing written", file=sys.stderr)
    if failed:
        print(f"    failed: {failed}", file=sys.stderr)
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
