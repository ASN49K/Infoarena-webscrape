#!/usr/bin/env python3
"""
Full dump of an infoarena problem into a single directory.

Given a problem slug, this combines the two existing scripts:
  - scrape_infoarena.py     -> submissions metadata (CSV) + solution sources
  - download_attachments.py -> test cases / extra data attachments

Layout produced (all problems collected under one base directory):
    infoarena/
        <problem>/                       e.g. infoarena/cmlsc/, infoarena/fmcm/
            <problem>.csv        general data (all submissions)
            solution.txt         "Indicatii de rezolvare" hints, if the problem has any
                                 (else solution_MISSING.txt, holding just the link)
            solutions/           one source file per submission (<id>.<ext>)
            details/             one per-test report CSV per submission (<id>.csv)
            tests/               downloaded attachments (test data, graders, ...)

Usage:
    python3 infoarena_dump.py cmlsc
    python3 infoarena_dump.py cmlsc --max-pages 2      # limit submissions (debug)
    python3 infoarena_dump.py cmlsc --no-code          # skip solution sources
    python3 infoarena_dump.py cmlsc --no-details       # skip per-test reports
    python3 infoarena_dump.py cmlsc --no-solution      # skip the hints (solution.txt)
    python3 infoarena_dump.py cmlsc --no-attachments   # skip test data
    python3 infoarena_dump.py cmlsc --code-delay 0.05 --attach-delay 0.2

Requires scrape_infoarena.py and download_attachments.py in the same folder.
"""

import argparse
import csv
import os
import sys

import scrape_infoarena as subs
import download_attachments as att

CSV_FIELDS = ["id", "user", "full_name", "problem", "size", "date", "score",
              "status", "language", "compiler", "source_file",
              "num_tests", "num_subtasks", "url"]


def dump_submissions(task, root, solutions_dir, details_dir, max_pages,
                     want_code, want_details, keep_langs, drop_missing_code=True):
    code_dir = solutions_dir if want_code else None
    if code_dir:
        os.makedirs(code_dir, exist_ok=True)
    det_dir = details_dir if want_details else None
    if det_dir:
        os.makedirs(det_dir, exist_ok=True)

    print(f"[submissions] scraping '{task}' ...", file=sys.stderr)
    if keep_langs:
        print(f"[submissions] language filter: keeping {sorted(keep_langs)}", file=sys.stderr)
    rows = subs.scrape(task, max_pages=max_pages, code_dir=code_dir,
                       keep_langs=keep_langs, details_dir=det_dir,
                       drop_missing_code=drop_missing_code)

    for r in rows:
        r.setdefault("language", "")
        r.setdefault("compiler", "")
        r.setdefault("source_file", "")
        r.setdefault("num_tests", "")
        r.setdefault("num_subtasks", "")

    csv_path = os.path.join(root, f"{task}.csv")
    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=CSV_FIELDS)
        w.writeheader()
        w.writerows(rows)
    print(f"[submissions] {len(rows)} rows -> {csv_path}", file=sys.stderr)
    if want_code:
        print(f"[submissions] sources -> {solutions_dir}/", file=sys.stderr)
    if want_details:
        print(f"[submissions] per-test reports -> {details_dir}/", file=sys.stderr)


def dump_attachments(task, tests_dir, delay, do_unzip):
    os.makedirs(tests_dir, exist_ok=True)
    print(f"[attachments] listing '{task}' ...", file=sys.stderr)
    names = att.list_attachments(task)
    if not names:
        print("[attachments] none found.", file=sys.stderr)
        return
    print(f"[attachments] {len(names)} files -> {tests_dir}/", file=sys.stderr)

    zips = []
    for name in names:
        try:
            path = att.download(task, name, tests_dir, delay)
        except Exception as e:
            print(f"  ! {name}: {e}", file=sys.stderr)
            continue
        if path.lower().endswith(".zip"):
            zips.append(path)

    if zips and do_unzip:
        print(f"[attachments] unzipping {len(zips)} archive(s) ...", file=sys.stderr)
        for z in zips:
            try:
                att.unzip(z, tests_dir)
            except Exception as e:
                print(f"  ! unzip {z}: {e}", file=sys.stderr)


def main():
    ap = argparse.ArgumentParser(description="Dump a full infoarena problem into one directory.")
    ap.add_argument("task", help="problem slug, e.g. cmlsc")
    ap.add_argument("-o", "--output",
                    help="root directory for this problem (default: <base-dir>/<task>, "
                         "e.g. infoarena/cmlsc). Overrides --base-dir.")
    ap.add_argument("--base-dir", default="infoarena",
                    help="parent directory holding one subdirectory per problem "
                         "(default: infoarena)")
    ap.add_argument("--max-pages", type=int, help="limit submission pages (debug)")
    ap.add_argument("--langs",
                    help="only save solutions in these languages, comma-separated "
                         "(e.g. 'c,cpp,rust,python'). Others are skipped but still in the CSV.")
    ap.add_argument("--no-code", action="store_true", help="skip downloading solution sources")
    ap.add_argument("--keep-missing", action="store_true",
                    help="keep submissions whose source is not accessible "
                         "(default: drop them from the CSV)")
    ap.add_argument("--no-details", action="store_true",
                    help="skip parsing per-test evaluation reports")
    ap.add_argument("--no-solution", action="store_true",
                    help="skip saving the problem's 'Indicatii de rezolvare' hints")
    ap.add_argument("--no-attachments", action="store_true", help="skip downloading test data")
    ap.add_argument("--no-unzip", action="store_true", help="do not extract .zip attachments")
    ap.add_argument("--code-delay", type=float, help="delay between source downloads (s)")
    ap.add_argument("--attach-delay", type=float, default=0.2,
                    help="delay between attachment downloads (default 0.2s)")
    ap.add_argument("--cookie",
                    help="infoarena session cookie (or set INFOARENA_COOKIE) to also "
                         "fetch login-gated sources. Copy the 'Cookie' request header "
                         "from your logged-in browser's DevTools.")
    args = ap.parse_args()

    if args.cookie:
        subs.COOKIE = args.cookie

    root = args.output or os.path.join(args.base_dir, args.task)
    solutions_dir = os.path.join(root, "solutions")
    details_dir = os.path.join(root, "details")
    tests_dir = os.path.join(root, "tests")
    os.makedirs(root, exist_ok=True)

    if args.code_delay is not None:
        subs.DELAY = args.code_delay   # override the module's politeness delay

    keep_langs = subs.parse_langs(args.langs)

    print(f"=== infoarena dump: {args.task} -> {root}/ ===", file=sys.stderr)
    dump_submissions(args.task, root, solutions_dir, details_dir, args.max_pages,
                     not args.no_code, not args.no_details, keep_langs,
                     drop_missing_code=not args.keep_missing)

    if not args.no_solution:
        path, found = subs.save_solution(args.task, root)
        tag = "hints saved" if found else "NONE - marked MISSING"
        print(f"[solution] {tag} -> {path}", file=sys.stderr)

    if not args.no_attachments:
        dump_attachments(args.task, tests_dir, args.attach_delay, not args.no_unzip)

    print(f"=== done: {root}/ ===", file=sys.stderr)


if __name__ == "__main__":
    main()
