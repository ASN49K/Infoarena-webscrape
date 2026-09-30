#!/usr/bin/env python3

import argparse
import csv
import os
import shutil
import sys

import scrape_infoarena as subs
import download_attachments as att

CSV_FIELDS = ["id", "user", "full_name", "problem", "size", "date", "score",
              "status", "language", "compiler", "source_file",
              "num_tests", "num_subtasks", "url"]


def dump_submissions(task, root, solutions_dir, details_dir, submissions_dir,
                     max_pages, want_code, want_details, want_json, keep_langs,
                     drop_missing_code=True):
    code_dir = solutions_dir if want_code else None
    if code_dir:
        os.makedirs(code_dir, exist_ok=True)
    det_dir = details_dir if want_details else None
    if det_dir:
        os.makedirs(det_dir, exist_ok=True)
    subs_dir = submissions_dir if want_json else None
    if subs_dir:
        os.makedirs(subs_dir, exist_ok=True)

    csv_path = os.path.join(root, f"{task}.csv")
    prior = subs.load_prior_rows(csv_path)

    print(f"[submissions] scraping '{task}' ...", file=sys.stderr)
    if keep_langs:
        print(f"[submissions] language filter: keeping {sorted(keep_langs)}", file=sys.stderr)
    rows = subs.scrape(task, max_pages=max_pages, code_dir=code_dir,
                       keep_langs=keep_langs, details_dir=det_dir,
                       drop_missing_code=drop_missing_code,
                       submissions_dir=subs_dir, prior=prior)

    for r in rows:
        r.setdefault("language", "")
        r.setdefault("compiler", "")
        r.setdefault("source_file", "")
        r.setdefault("num_tests", "")
        r.setdefault("num_subtasks", "")

    if max_pages is not None and prior:
        fresh = {r["id"] for r in rows if r.get("id")}
        carried = [{k: p.get(k, "") for k in CSV_FIELDS}
                   for jid, p in prior.items() if jid not in fresh]
        if carried:
            rows = rows + carried
            rows.sort(key=lambda r: int(r["id"]) if str(r.get("id", "")).isdigit()
                      else -1, reverse=True)
            print(f"[submissions] kept {len(carried)} row(s) from the previous CSV "
                  f"that this --max-pages run did not reach", file=sys.stderr)

    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=CSV_FIELDS)
        w.writeheader()
        w.writerows(rows)
    print(f"[submissions] {len(rows)} rows -> {csv_path}", file=sys.stderr)
    if want_code:
        print(f"[submissions] sources -> {solutions_dir}/", file=sys.stderr)
    if want_details:
        print(f"[submissions] per-test reports -> {details_dir}/", file=sys.stderr)
    if want_json:
        print(f"[submissions] per-submission JSON -> {submissions_dir}/", file=sys.stderr)


def dump_attachments(task, tests_dir, delay, do_unzip, force=False):
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
            path = att.download(task, name, tests_dir, delay, force=force)
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


def zip_problem(root):
    root = os.path.normpath(root)
    parent = os.path.dirname(root) or "."
    name = os.path.basename(root)
    archive = shutil.make_archive(root, "zip", root_dir=parent, base_dir=name)
    shutil.rmtree(root)
    return archive


def unzip_problem(root):
    root = os.path.normpath(root)
    archive = root + ".zip"
    parent = os.path.dirname(root) or "."
    shutil.unpack_archive(archive, parent, "zip")
    os.remove(archive)
    return archive


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
                         "(e.g. 'c,cpp,rust,python'). Others are skipped but still in the CSV. "
                         "Defaults to 'c,cpp,java'; pass 'all' to save every language.")
    ap.add_argument("--no-code", action="store_true", help="skip downloading solution sources")
    ap.add_argument("--keep-missing", action="store_true",
                    help="keep submissions whose source is not accessible "
                         "(default: drop them from the CSV)")
    ap.add_argument("--no-details", action="store_true",
                    help="skip parsing per-test evaluation reports")
    ap.add_argument("--no-json", action="store_true",
                    help="skip writing the per-submission JSON (submissions/) and "
                         "the problem JSON (<task>.json)")
    ap.add_argument("--no-solution", action="store_true",
                    help="skip saving the problem's 'Indicatii de rezolvare' hints")
    ap.add_argument("--no-statement", action="store_true",
                    help="skip saving the problem's statement (statement.txt)")
    ap.add_argument("--no-attachments", action="store_true", help="skip downloading test data")
    ap.add_argument("--zip", action="store_true",
                    help="after processing, compress the problem directory into "
                         "<root>.zip and delete the original folder to save disk space")
    ap.add_argument("--refetch", metavar="KIND[,KIND...]",
                    help="fetch these again even though they are already on disk: "
                         + ", ".join(subs.REFETCH_KINDS) + ", or 'all'. Only what "
                         "this run actually visits is refreshed, so combining it "
                         "with --max-pages updates the newest submissions and "
                         "leaves every older one untouched. Unlike --force, "
                         "nothing is deleted up front")
    ap.add_argument("--force", action="store_true",
                    help="discard an existing <root>.zip and re-dump from scratch, "
                         "losing everything already downloaded (by default the "
                         "archive is unzipped and the dump resumes into it, "
                         "fetching only what is missing). To refresh specific "
                         "artefacts without throwing the rest away, use --refetch")
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

    if args.refetch:
        wanted = {k.strip().lower() for k in args.refetch.split(",") if k.strip()}
        if "all" in wanted:
            wanted = set(subs.REFETCH_KINDS)
        unknown = wanted - set(subs.REFETCH_KINDS)
        if unknown:
            ap.error(f"unknown --refetch kind(s): {', '.join(sorted(unknown))}. "
                     f"Choose from: {', '.join(subs.REFETCH_KINDS)}, all")
        subs.REFETCH = wanted
        print(f"[refetch] re-fetching {', '.join(sorted(wanted))} "
              f"(existing files are overwritten as they are reached, "
              f"never deleted up front)", file=sys.stderr)

    root = args.output or os.path.join(args.base_dir, args.task)

    zip_path = os.path.normpath(root) + ".zip"
    if os.path.exists(zip_path):
        if args.force:
            os.remove(zip_path)
            print(f"[force] discarded {zip_path}; re-dumping from scratch",
                  file=sys.stderr)
        else:
            print(f"[resume] expanding {zip_path} to check existing contents ...",
                  file=sys.stderr)
            unzip_problem(root)

    solutions_dir = os.path.join(root, "solutions")
    details_dir = os.path.join(root, "details")
    submissions_dir = os.path.join(root, "submissions")
    tests_dir = os.path.join(root, "tests")
    os.makedirs(root, exist_ok=True)

    want_json = not args.no_json and not args.no_code and not args.no_details

    if args.code_delay is not None:
        subs.DELAY = args.code_delay

    keep_langs = subs.parse_langs(args.langs)

    print(f"=== infoarena dump: {args.task} -> {root}/ ===", file=sys.stderr)
    dump_submissions(args.task, root, solutions_dir, details_dir, submissions_dir,
                     args.max_pages, not args.no_code, not args.no_details,
                     want_json, keep_langs, drop_missing_code=not args.keep_missing)

    if not args.no_solution:
        path, found = subs.save_solution(args.task, root)
        tag = "hints saved" if found else "NONE - marked MISSING"
        print(f"[solution] {tag} -> {path}", file=sys.stderr)

    if not args.no_statement:
        path, found = subs.save_statement(args.task, root)
        tag = "statement saved" if found else "NONE - marked MISSING"
        print(f"[statement] {tag} -> {path}", file=sys.stderr)

    if not args.no_json:
        path, ok = subs.save_problem_json(args.task, root)
        tag = "problem JSON saved" if ok else "FAILED to parse"
        print(f"[problem-json] {tag} -> {path}", file=sys.stderr)

    if not args.no_attachments:
        dump_attachments(args.task, tests_dir, args.attach_delay, not args.no_unzip,
                         force=subs.refetching("attachments"))

    if args.zip:
        archive = zip_problem(root)
        print(f"[zip] {archive} (folder removed)", file=sys.stderr)
        print(f"=== done: {archive} ===", file=sys.stderr)
    else:
        print(f"=== done: {root}/ ===", file=sys.stderr)


if __name__ == "__main__":
    main()
