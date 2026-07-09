#!/usr/bin/env python3
"""
Count submissions collected under the infoarena/ directory, so you can monitor
how much data you've dumped.

For each problem subdirectory it reports:
  - submissions: data rows in <problem>.csv (the authoritative count)
  - solutions:   source files saved in solutions/
  - details:     per-test report CSVs in details/
  - tests:       "yes" if test data was downloaded (tests/ has files), else "no"
  - hints:       "yes" if solution.txt exists, "MISSING" if solution_MISSING.txt
  - complete:    number of submissions that have a details file in a problem
                 whose tests AND hints both exist (0 if tests or hints are missing)

Usage:
    python3 count_submissions.py                 # scans ./infoarena
    python3 count_submissions.py path/to/infoarena
    python3 count_submissions.py --csv           # machine-readable output
"""

import argparse
import csv
import os
import sys


def count_csv_rows(path):
    """Number of data rows (excluding the header) in a CSV, or 0 if unreadable."""
    try:
        with open(path, newline="", encoding="utf-8") as f:
            n = sum(1 for _ in csv.reader(f))
        return max(0, n - 1)          # drop the header row
    except OSError:
        return 0


def count_files(directory):
    """Number of regular files directly inside `directory` (0 if it's absent)."""
    if not os.path.isdir(directory):
        return 0
    return sum(1 for e in os.scandir(directory) if e.is_file())


def scan_problem(pdir):
    """Return a stats dict for one problem directory."""
    name = os.path.basename(pdir.rstrip("/"))
    csv_path = os.path.join(pdir, f"{name}.csv")
    if not os.path.isfile(csv_path):      # fall back to any single CSV in the dir
        csvs = [e.path for e in os.scandir(pdir)
                if e.is_file() and e.name.endswith(".csv")]
        csv_path = csvs[0] if len(csvs) == 1 else csv_path

    if os.path.isfile(os.path.join(pdir, "solution.txt")):
        hints = "yes"
    elif os.path.isfile(os.path.join(pdir, "solution_MISSING.txt")):
        hints = "MISSING"
    else:
        hints = "-"

    details = count_files(os.path.join(pdir, "details"))
    has_tests = count_files(os.path.join(pdir, "tests")) > 0
    has_hints = hints == "yes"
    # submissions with a details file, but only when tests and hints both exist
    complete = details if (has_tests and has_hints) else 0

    return {
        "problem":     name,
        "submissions": count_csv_rows(csv_path),
        "solutions":   count_files(os.path.join(pdir, "solutions")),
        "details":     details,
        "tests":       "yes" if has_tests else "no",
        "hints":       hints,
        "complete":    complete,
    }


def main():
    ap = argparse.ArgumentParser(
        description="Count submissions collected under the infoarena/ directory.")
    ap.add_argument("base", nargs="?", default="infoarena",
                    help="the collection directory (default: infoarena)")
    ap.add_argument("--csv", action="store_true",
                    help="print machine-readable CSV instead of a table")
    args = ap.parse_args()

    if not os.path.isdir(args.base):
        print(f"error: '{args.base}' is not a directory", file=sys.stderr)
        return 1

    problems = sorted(e.path for e in os.scandir(args.base) if e.is_dir())
    stats = [scan_problem(p) for p in problems]

    fields = ["problem", "submissions", "solutions", "details",
              "tests", "hints", "complete"]
    if args.csv:
        w = csv.DictWriter(sys.stdout, fieldnames=fields)
        w.writeheader()
        w.writerows(stats)
        return 0

    if not stats:
        print(f"No problem directories found under '{args.base}/'.")
        return 0

    total_sub = sum(s["submissions"] for s in stats)
    total_sol = sum(s["solutions"] for s in stats)
    total_det = sum(s["details"] for s in stats)
    total_cmp = sum(s["complete"] for s in stats)

    wname = max([len("problem")] + [len(s["problem"]) for s in stats])
    header = (f"{'problem':<{wname}}  {'subs':>7}  {'solutions':>9}  {'details':>7}  "
              f"{'tests':>5}  {'hints':>7}  {'complete':>8}")
    print(header)
    print("-" * len(header))
    for s in stats:
        print(f"{s['problem']:<{wname}}  {s['submissions']:>7}  "
              f"{s['solutions']:>9}  {s['details']:>7}  {s['tests']:>5}  "
              f"{s['hints']:>7}  {s['complete']:>8}")
    print("-" * len(header))
    print(f"{'TOTAL':<{wname}}  {total_sub:>7}  {total_sol:>9}  {total_det:>7}  "
          f"{'':>5}  {'':>7}  {total_cmp:>8}    ({len(stats)} problems)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
