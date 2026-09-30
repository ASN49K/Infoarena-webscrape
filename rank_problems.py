#!/usr/bin/env python3

import argparse
import concurrent.futures
import re
import sys
import time

import scrape_infoarena as subs
from dump_archive import PROBLEMS

COUNT_RE = re.compile(r'\((\d+)\s*rezultate?\)')

ARHIVA = "https://www.infoarena.ro/arhiva"
ARHIVA_EDU = "https://www.infoarena.ro/arhiva-educationala"
LIST_PAGE = 250

ARHIVA_ROW_RE = re.compile(
    r'<td class="number">(\d+)</td>.*?'
    r'<a href="/problema/([^"]+)">([^<]*)</a>.*?'
    r'<td class="source">(.*?)</td>'
    r'<td class="">(\d+)</td>',
    re.S)

EDU_ROW_RE = re.compile(r'<a href="/problema/([^"]+)">([^<]*)</a>')

EDU, MAIN = "educational", "main"


def _text(raw):
    import html
    return html.unescape(re.sub(r"<[^>]+>", "", raw)).strip()


def list_pages(url):
    first = 0
    while True:
        html = subs.get(f"{url}?display_entries={LIST_PAGE}&first_entry={first}")
        yield html
        m = COUNT_RE.search(html)
        total = int(m.group(1)) if m else 0
        first += LIST_PAGE
        if first >= total:
            return
        time.sleep(subs.DELAY)


def edu_titles():
    titles = {}
    try:
        for html in list_pages(ARHIVA_EDU):
            for slug, title in EDU_ROW_RE.findall(html):
                titles.setdefault(slug, _text(title))
    except Exception as e:
        print(f"  ! educational listing: {e}", file=sys.stderr)
    return titles


def edu_problems():
    titles = edu_titles()
    return [{"slug": s, "title": titles.get(s, s), "archive": EDU,
             "source": "Arhiva educationala", "solved": None} for s in PROBLEMS]


def main_problems():
    out, seen = [], set()
    for html in list_pages(ARHIVA):
        for _, slug, title, source, solved in ARHIVA_ROW_RE.findall(html):
            if slug in seen:
                continue
            seen.add(slug)
            out.append({"slug": slug, "title": _text(title), "archive": MAIN,
                        "source": _text(source), "solved": int(solved)})
    return out


def total_submissions(task):
    html = subs.get(f"{subs.BASE}?task={task}&display_entries=1&first_entry=0")
    m = COUNT_RE.search(html)
    return int(m.group(1)) if m else None


def fill_counts(problems, workers):
    done = 0
    total = len(problems)

    def work(p):
        try:
            p["submissions"] = total_submissions(p["slug"])
        except Exception as e:
            print(f"  ! {p['slug']}: {e}", file=sys.stderr)
            p["submissions"] = None
        time.sleep(subs.DELAY)
        return p

    with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as pool:
        for p in pool.map(work, problems):
            done += 1
            if done % 25 == 0 or done == total:
                print(f"  {done}/{total} problems...", file=sys.stderr)


def stats(rows):
    ns = sorted(r["submissions"] for r in rows if r["submissions"] is not None)
    if not ns:
        return len(rows), 0, 0, 0, 0
    mid = len(ns) // 2
    median = ns[mid] if len(ns) % 2 else (ns[mid - 1] + ns[mid]) // 2
    return len(rows), sum(ns), sum(ns) // len(ns), median, ns[-1]


def print_summary(rows):
    groups = [("educational archive", [r for r in rows if r["archive"] == EDU]),
              ("main archive", [r for r in rows if r["archive"] == MAIN])]
    groups = [(name, g) for name, g in groups if g]
    grand = sum(r["submissions"] or 0 for r in rows) or 1

    head = (f"{'archive':<20}  {'problems':>8}  {'submissions':>12}  {'share':>6}"
            f"  {'mean':>8}  {'median':>8}  {'max':>8}")
    print()
    print(head)
    print("-" * len(head))
    for name, g in groups:
        n, tot, mean, med, mx = stats(g)
        print(f"{name:<20}  {n:>8,}  {tot:>12,}  {100*tot/grand:>5.1f}%"
              f"  {mean:>8,}  {med:>8,}  {mx:>8,}")
    print("-" * len(head))
    n, tot, mean, med, mx = stats(rows)
    print(f"{'TOTAL':<20}  {n:>8,}  {tot:>12,}  {100.0:>5.1f}%"
          f"  {mean:>8,}  {med:>8,}  {mx:>8,}")
    missing = sum(1 for r in rows if r["submissions"] is None)
    if missing:
        print(f"\n({missing} problem(s) could not be read; shown as ERR)")


def print_table(rows, top):
    shown = rows if top <= 0 else rows[:top]
    wslug = max(len(r["slug"]) for r in shown)
    wtitle = min(34, max(len(r["title"]) for r in shown))
    head = (f"{'#':>5}  {'problem':<{wslug}}  {'title':<{wtitle}}  "
            f"{'archive':<11}  {'submissions':>11}  {'solved by':>9}")
    print(head)
    print("-" * len(head))
    for i, r in enumerate(shown, 1):
        n = r["submissions"]
        title = r["title"][:wtitle]
        solved = f"{r['solved']:,}" if r["solved"] is not None else "-"
        count = f"{n:,}" if n is not None else "ERR"
        print(f"{i:>5}  {r['slug']:<{wslug}}  {title:<{wtitle}}  "
              f"{r['archive']:<11}  {count:>11}  {solved:>9}")
    if top > 0 and len(rows) > top:
        print(f"... {len(rows) - top:,} more (use --top 0 to show every problem)")


def main():
    ap = argparse.ArgumentParser(
        description="Rank infoarena problems by total submissions.")
    ap.add_argument("--csv", action="store_true",
                    help="print CSV (always every row) instead of a table")
    ap.add_argument("--archive", choices=["all", "edu", "main"], default="all",
                    help="which archive to rank (default: all)")
    ap.add_argument("--top", type=int, default=50,
                    help="rows to print, 0 for all (default: 50)")
    ap.add_argument("--workers", type=int, default=8,
                    help="parallel monitor requests (default: 8)")
    ap.add_argument("--cookie", help="infoarena session cookie (or INFOARENA_COOKIE)")
    args = ap.parse_args()
    if args.cookie:
        subs.COOKIE = args.cookie

    problems = []
    if args.archive in ("all", "edu"):
        problems += edu_problems()
    if args.archive in ("all", "main"):
        print("reading the main archive listing...", file=sys.stderr)
        problems += main_problems()
    if not problems:
        print("no problems to rank", file=sys.stderr)
        return 1

    print(f"counting submissions for {len(problems):,} problems "
          f"({args.workers} workers)...", file=sys.stderr)
    fill_counts(problems, max(1, args.workers))

    problems.sort(key=lambda r: (-(r["submissions"] if r["submissions"] is not None
                                   else -1), r["slug"]))

    if args.csv:
        import csv
        w = csv.writer(sys.stdout)
        w.writerow(["problem", "title", "archive", "source", "submissions", "solved_by"])
        for r in problems:
            w.writerow([r["slug"], r["title"], r["archive"], r["source"],
                        r["submissions"] if r["submissions"] is not None else "",
                        r["solved"] if r["solved"] is not None else ""])
        return 0

    print_table(problems, args.top)
    print_summary(problems)
    return 0


if __name__ == "__main__":
    sys.exit(main())
