#!/usr/bin/env python3
"""
Rank the educational-archive problems by their TOTAL number of submissions on
infoarena (read live from the website, not from the local dataset).

For each problem it makes one lightweight monitor request and reads the
"(N rezultate)" total. The problem list is reused from dump_archive.py, so
whatever you curate there is what gets ranked.

Usage:
    python3 rank_problems.py                 # ranked table, most submissions first
    python3 rank_problems.py --csv           # machine-readable (slug,submissions)
    python3 rank_problems.py --cookie "..."  # forwarded to the requests if needed
"""

import argparse
import re
import sys
import time

import scrape_infoarena as subs
from dump_archive import PROBLEMS

COUNT_RE = re.compile(r'\((\d+)\s*rezultate\)')


def total_submissions(task):
    """Total submissions the website reports for a problem, or None."""
    html = subs.get(f"{subs.BASE}?task={task}&display_entries=1&first_entry=0")
    m = COUNT_RE.search(html)
    return int(m.group(1)) if m else None


def main():
    ap = argparse.ArgumentParser(
        description="Rank archive problems by total submissions on infoarena.")
    ap.add_argument("--csv", action="store_true", help="print CSV instead of a table")
    ap.add_argument("--cookie", help="infoarena session cookie (or INFOARENA_COOKIE)")
    args = ap.parse_args()
    if args.cookie:
        subs.COOKIE = args.cookie

    rows = []
    for slug in PROBLEMS:
        try:
            n = total_submissions(slug)
        except Exception as e:
            print(f"  ! {slug}: {e}", file=sys.stderr)
            n = None
        rows.append((slug, n))
        print(f"  {slug}: {n}", file=sys.stderr)
        time.sleep(subs.DELAY)

    # most submissions first; unknown counts sink to the bottom, ties by name
    rows.sort(key=lambda r: (-(r[1] if r[1] is not None else -1), r[0]))

    if args.csv:
        import csv
        w = csv.writer(sys.stdout)
        w.writerow(["problem", "submissions"])
        w.writerows((s, n if n is not None else "") for s, n in rows)
        return 0

    width = max(len(s) for s, _ in rows)
    print(f"{'#':>3}  {'problem':<{width}}  {'submissions':>11}")
    print("-" * (3 + 2 + width + 2 + 11))
    for i, (slug, n) in enumerate(rows, 1):
        shown = f"{n:,}" if n is not None else "ERR"
        print(f"{i:>3}  {slug:<{width}}  {shown:>11}")
    total = sum(n for _, n in rows if n)
    print("-" * (3 + 2 + width + 2 + 11))
    print(f"{'':>3}  {'TOTAL':<{width}}  {total:>11,}   ({len(rows)} problems)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
