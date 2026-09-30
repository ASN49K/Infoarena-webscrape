#!/usr/bin/env python3

import argparse
import csv
import os
import sys
import zipfile


class DirSource:
    def __init__(self, path):
        self.path = os.path.normpath(path)
        self.name = os.path.basename(self.path)

    def files_in(self, subdir=""):
        d = os.path.join(self.path, subdir) if subdir else self.path
        if not os.path.isdir(d):
            return []
        return [e.name for e in os.scandir(d) if e.is_file()]

    def read_text(self, rel):
        try:
            with open(os.path.join(self.path, rel), encoding="utf-8",
                      errors="replace") as f:
                return f.read()
        except OSError:
            return None


class ZipSource:
    def __init__(self, path):
        self.path = path
        with zipfile.ZipFile(path) as z:
            self.names = z.namelist()
        tops = {n.split("/", 1)[0] for n in self.names if n}
        self.name = tops.pop() if len(tops) == 1 else os.path.basename(path)[:-4]

    def files_in(self, subdir=""):
        prefix = f"{self.name}/{subdir}/" if subdir else f"{self.name}/"
        out = []
        for n in self.names:
            if n.startswith(prefix):
                rest = n[len(prefix):]
                if rest and "/" not in rest:
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
    text = src.read_text(name)
    if text is None:
        return 0
    n = sum(1 for _ in csv.reader(text.splitlines()))
    return max(0, n - 1)


def scan_problem(src):
    name = src.name
    top_files = src.files_in("")
    csv_name = f"{name}.csv"
    if csv_name not in top_files:
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
    complete = details if (has_tests and has_hints) else 0

    json_subs = len([f for f in src.files_in("submissions") if f.endswith(".json")])
    has_pjson = f"{name}.json" in top_files

    return {
        "problem": name,
        "submissions": count_csv_rows(src, csv_name),
        "solutions": len(src.files_in("solutions")),
        "details": details,
        "json": json_subs,
        "pjson": "yes" if has_pjson else "-",
        "tests": "yes" if has_tests else "no",
        "hints": hints,
        "complete": complete,
    }


def collect_sources(base):
    sources = {}
    for e in sorted(os.scandir(base), key=lambda e: e.name):
        if e.is_dir():
            sources[e.name] = DirSource(e.path)
    for e in sorted(os.scandir(base), key=lambda e: e.name):
        if e.is_file() and e.name.endswith(".zip"):
            stem = e.name[:-4]
            if stem not in sources:
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

    fields = ["problem", "submissions", "solutions", "details", "json", "pjson",
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
    total_json = sum(s["json"] for s in stats)
    total_cmp = sum(s["complete"] for s in stats)

    wname = max([len("problem")] + [len(s["problem"]) for s in stats])
    header = (f"{'problem':<{wname}}  {'subs':>7}  {'solutions':>9}  {'details':>7}  "
              f"{'json':>7}  {'pjson':>5}  {'tests':>5}  {'hints':>7}  {'complete':>8}")
    print(header)
    print("-" * len(header))
    for s in stats:
        print(f"{s['problem']:<{wname}}  {s['submissions']:>7}  "
              f"{s['solutions']:>9}  {s['details']:>7}  {s['json']:>7}  "
              f"{s['pjson']:>5}  {s['tests']:>5}  {s['hints']:>7}  {s['complete']:>8}")
    print("-" * len(header))
    print(f"{'TOTAL':<{wname}}  {total_sub:>7}  {total_sol:>9}  {total_det:>7}  "
          f"{total_json:>7}  {'':>5}  {'':>5}  {'':>7}  {total_cmp:>8}    "
          f"({len(stats)} problems)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
