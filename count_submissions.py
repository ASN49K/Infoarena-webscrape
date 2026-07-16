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

A problem may be stored either as a plain directory (infoarena/<problem>/) or,
once compressed by `infoarena_dump.py --zip`, as an archive (infoarena/<problem>.zip).
Zipped problems are read straight out of the archive without unpacking, so
counting never re-inflates them to disk. If both forms exist for a problem, the
directory is used.

Usage:
    python3 count_submissions.py                 # scans ./infoarena
    python3 count_submissions.py path/to/infoarena
    python3 count_submissions.py --csv           # machine-readable output
"""

import argparse
import csv
import os
import sys
import zipfile


class DirSource:
    """A problem stored as a plain directory on disk."""

    def __init__(self, path):
        self.path = os.path.normpath(path)
        self.name = os.path.basename(self.path)

    def files_in(self, subdir=""):
        """File names directly inside subdir ('' = the problem's top level)."""
        d = os.path.join(self.path, subdir) if subdir else self.path
        if not os.path.isdir(d):
            return []
        return [e.name for e in os.scandir(d) if e.is_file()]

    def read_text(self, rel):
        """Full text of member `rel`, or None if it's absent/unreadable."""
        try:
            with open(os.path.join(self.path, rel), encoding="utf-8",
                      errors="replace") as f:
                return f.read()
        except OSError:
            return None


class ZipSource:
    """A problem stored as a <problem>.zip archive (read without unpacking).

    Inside the archive every path is prefixed with a single top-level folder
    (the problem directory as it was zipped), e.g. 'cmlsc/details/1.csv'. That
    prefix is detected from the entries rather than assumed from the filename.
    """

    def __init__(self, path):
        self.path = path
        with zipfile.ZipFile(path) as z:
            self.names = z.namelist()
        tops = {n.split("/", 1)[0] for n in self.names if n}
        # Normal case: one top-level folder == the problem name.
        self.name = tops.pop() if len(tops) == 1 else os.path.basename(path)[:-4]

    def files_in(self, subdir=""):
        prefix = f"{self.name}/{subdir}/" if subdir else f"{self.name}/"
        out = []
        for n in self.names:
            if n.startswith(prefix):
                rest = n[len(prefix):]
                if rest and "/" not in rest:      # a file directly inside prefix
                    out.append(rest)
        return out

    def read_text(self, rel):
        member = f"{self.name}/{rel}"
        try:
            with zipfile.ZipFile(self.path) as z, z.open(member) as f:
                return f.read().decode("utf-8", "replace")
        except (KeyError, OSError, zipfile.BadZipFile):
            return None


def count_csv_rows(src, name):
    """Data rows (excluding the header) in member `name`, or 0 if unreadable."""
    text = src.read_text(name)
    if text is None:
        return 0
    n = sum(1 for _ in csv.reader(text.splitlines()))
    return max(0, n - 1)              # drop the header row


def scan_problem(src):
    """Return a stats dict for one problem, from a Dir or Zip source."""
    name = src.name
    top_files = src.files_in("")
    csv_name = f"{name}.csv"
    if csv_name not in top_files:         # fall back to any single CSV present
        csvs = [f for f in top_files if f.endswith(".csv")]
        csv_name = csvs[0] if len(csvs) == 1 else csv_name

    if "solution.txt" in top_files:
        hints = "yes"
    elif "solution_MISSING.txt" in top_files:
        hints = "MISSING"
    else:
        hints = "-"

    details = len(src.files_in("details"))
    has_tests = len(src.files_in("tests")) > 0
    has_hints = hints == "yes"
    # submissions with a details file, but only when tests and hints both exist
    complete = details if (has_tests and has_hints) else 0

    return {
        "problem":     name,
        "submissions": count_csv_rows(src, csv_name),
        "solutions":   len(src.files_in("solutions")),
        "details":     details,
        "tests":       "yes" if has_tests else "no",
        "hints":       hints,
        "complete":    complete,
    }


def collect_sources(base):
    """One source per problem under `base`; a directory wins over a .zip."""
    sources = {}
    for e in sorted(os.scandir(base), key=lambda e: e.name):
        if e.is_dir():
            sources[e.name] = DirSource(e.path)
    for e in sorted(os.scandir(base), key=lambda e: e.name):
        if e.is_file() and e.name.endswith(".zip"):
            stem = e.name[:-4]
            if stem not in sources:       # keep the uncompressed copy if present
                try:
                    sources[stem] = ZipSource(e.path)
                except zipfile.BadZipFile:
                    print(f"warning: skipping unreadable archive '{e.path}'",
                          file=sys.stderr)
    return [sources[k] for k in sorted(sources)]


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

    stats = [scan_problem(src) for src in collect_sources(args.base)]

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
