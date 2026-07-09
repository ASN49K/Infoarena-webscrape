#!/usr/bin/env python3
"""
Scrape submissions ("monitor") from infoarena for a given problem.

Usage:
    python3 scrape_infoarena.py cmlsc                 # all pages -> cmlsc.csv
    python3 scrape_infoarena.py cmlsc --max-pages 3   # only first 3 pages
    python3 scrape_infoarena.py cmlsc -o out.csv      # custom output file

Notes:
- Only public metadata is scraped: submission id, user, problem, round,
  size, date and score/status.
- The actual source code (?action=view-source) is NOT accessible without
  being logged in AND having solved the problem, so it is not scraped here.
- Be polite: there is a delay between requests. Don't hammer the server.
"""

import argparse
import csv
import html
import os
import re
import sys
import time
import urllib.parse
import urllib.request

BASE = "https://www.infoarena.ro/monitor"
JOB  = "https://www.infoarena.ro/job_detail"
PROB = "https://www.infoarena.ro/problema"
SITE = "https://www.infoarena.ro"
PAGE_SIZE = 250          # rows per request (max that works reliably)
DELAY = 0.25             # seconds between requests
UA = "Mozilla/5.0 (compatible; infoarena-scraper/1.0)"

# Optional infoarena session cookie. Some submissions (older ones, or those you
# can only see while logged in) are gated behind a full login wall rather than
# the public "free sources" warning. Provide your browser's cookie (via
# --cookie or the INFOARENA_COOKIE env var) to fetch those too. Copy it from
# DevTools -> Network -> any request -> Request Headers -> "Cookie".
COOKIE = os.environ.get("INFOARENA_COOKIE", "")

# One <tr> ... </tr> at a time
ROW_RE = re.compile(r'<tr class="(?:odd|even)">(.*?)</tr>', re.S)

# Fields inside a row
ID_RE     = re.compile(r'/job_detail/(\d+)">#\d+')
USER_RE   = re.compile(r'<span class="username"><a href="[^"]*/utilizator/([^"]+)">([^<]*)</a>')
FULLNM_RE = re.compile(r'/utilizator/[^"]+"><img[^>]*/>([^<]*)</a>')
PROB_RE   = re.compile(r'/problema/([^"]+)">([^<]*)</a>')
ROUND_RE  = re.compile(r'<td ><a href="/([^"]+)">([^<]*)</a></td>\s*<td ><a href="/job_detail/\d+\?action=view-source">')
SIZE_RE   = re.compile(r'action=view-source">([^<]*)</a></td>')
DATE_RE   = re.compile(r'</a></td>\s*<td >([^<]*)</td>\s*<td ><a href="/job_detail/\d+"><span')
STATUS_RE = re.compile(r'<span class="job-status-[^"]*">([^<]*)</span>')

# view-source page: the code block and the compiler id
CODE_RE     = re.compile(r'<div class="code"><pre><code>(.*?)</code></pre>', re.S)
COMPILER_RE = re.compile(r'<td class="compiler-id">([^<]*)</td>')

# job_detail page: the per-test evaluation report ("Raport evaluator").
# The table has one <tr> per test with cells:
#   test no. | exec time | memory | message | points/test  [ | points/group ]
# The trailing "points/group" cell only appears on the FIRST test row of a
# group (as <td rowspan="N">group_score</td>) when the problem uses grouped
# scoring; ungrouped problems omit that column entirely. A final row spans the
# table with "Punctaj total".
EVAL_TABLE_RE = re.compile(r'<table class="job-eval-tests">(.*?)</table>', re.S)
EVAL_TBODY_RE = re.compile(r'<tbody>(.*?)</tbody>', re.S)
EVAL_ROW_RE   = re.compile(r'<tr[^>]*>(.*?)</tr>', re.S)
EVAL_CELL_RE  = re.compile(r'<td[^>]*>(.*?)</td>', re.S)
TAG_RE        = re.compile(r'<[^>]+>')

# Map an infoarena compiler-id to a canonical language family and a file
# extension. infoarena versions its compilers (cpp-64, cpp-32, c-64, fpc-64,
# ...) and the listing never shows the language, so we classify by prefix and
# treat anything unrecognised as "unknown" (kept as .txt, and reported).
#
# Each entry: prefix-matched compiler-id -> (language family, extension).
# Order matters: more specific prefixes must come before shorter ones
# (e.g. "cpp" before "c").
_LANG_RULES = [
    ("cpp",    ("cpp",    "cpp")),   # cpp, cpp-64, cpp-32, cpp11, ...
    ("gpp",    ("cpp",    "cpp")),
    ("g++",    ("cpp",    "cpp")),
    ("c-",     ("c",      "c")),     # c-64, c-32
    ("gcc",    ("c",      "c")),
    ("fpc",    ("pascal", "pas")),
    ("pascal", ("pascal", "pas")),
    ("rs",     ("rust",   "rs")),    # rs, rust
    ("rust",   ("rust",   "rs")),
    ("py",     ("python", "py")),    # py, python, python3
    ("python", ("python", "py")),
    ("java",   ("java",   "java")),
    ("kotlin", ("kotlin", "kt")),
    ("dotnet", ("csharp", "cs")),
    ("cs",     ("csharp", "cs")),
    ("csharp", ("csharp", "cs")),
    ("go",     ("go",     "go")),
    ("js",     ("javascript", "js")),
    ("node",   ("javascript", "js")),
]


def classify(compiler_id):
    """(language_family, extension) for a compiler-id. Unknown -> ('unknown','txt')."""
    cid = (compiler_id or "").strip().lower()
    # exact "c" is C (the "c-" prefix rule doesn't catch a bare "c")
    if cid == "c":
        return ("c", "c")
    for prefix, res in _LANG_RULES:
        if cid.startswith(prefix):
            return res
    return ("unknown", "txt")


# language family -> extension (used when resuming, to read language back from
# an already-downloaded file's extension)
_EXT_LANG = {"cpp": "cpp", "c": "c", "pas": "pascal", "rs": "rust", "py": "python",
             "java": "java", "kt": "kotlin", "cs": "csharp", "go": "go", "js": "javascript"}

# user-facing language aliases -> canonical family (for the --langs filter)
_LANG_ALIAS = {
    "c": "c",
    "cpp": "cpp", "c++": "cpp", "cxx": "cpp",
    "rust": "rust", "rs": "rust",
    "python": "python", "py": "python",
    "pascal": "pascal", "pas": "pascal",
    "java": "java", "kotlin": "kotlin",
    "csharp": "csharp", "c#": "csharp", "cs": "csharp",
    "go": "go", "javascript": "javascript", "js": "javascript",
}


def parse_langs(spec):
    """'c,cpp,rust,python' -> {'c','cpp','rust','python'}. None if spec is empty."""
    if not spec:
        return None
    keep = set()
    for tok in spec.split(","):
        tok = tok.strip().lower()
        if not tok:
            continue
        keep.add(_LANG_ALIAS.get(tok, tok))
    return keep or None


def _headers():
    h = {"User-Agent": UA}
    if COOKIE:
        h["Cookie"] = COOKIE
    return h


def get(url):
    req = urllib.request.Request(url, headers=_headers())
    with urllib.request.urlopen(req, timeout=30) as r:
        return r.read().decode("utf-8", "replace")


def post(url, data):
    body = urllib.parse.urlencode(data).encode()
    req = urllib.request.Request(url, data=body, headers=_headers())
    with urllib.request.urlopen(req, timeout=30) as r:
        return r.read().decode("utf-8", "replace")


def fetch(task, first_entry):
    url = f"{BASE}?task={task}&only_table=1&display_entries={PAGE_SIZE}&first_entry={first_entry}"
    return get(url)


def fetch_source(job_id):
    """Return (code, compiler_id) for a submission, or (None, None) if unavailable.

    For "free sources" problems, an anonymous visitor first gets a soft warning
    page ("nu ai punctaj maxim") instead of the code, carrying a 'Vezi sursa'
    (view anyway) button. That button just POSTs `force_view_source` back to the
    same URL, so we submit it to reveal the publicly-available source.
    """
    url = f"{JOB}/{job_id}?action=view-source"
    html_page = get(url)
    m = CODE_RE.search(html_page)
    if not m and "force_view_source" in html_page:
        html_page = post(url, {"force_view_source": "Vezi sursa"})
        m = CODE_RE.search(html_page)
    if not m:
        return None, None
    code = html.unescape(m.group(1))
    comp = COMPILER_RE.search(html_page)
    return code, (comp.group(1).strip() if comp else "")


def _cell_text(raw):
    """Strip tags/entities from a table cell's inner HTML -> plain text."""
    return html.unescape(TAG_RE.sub("", raw)).strip()


def _to_int(s):
    m = re.search(r'-?\d+', s or "")
    return int(m.group()) if m else 0


def _test_ok(message, points):
    """'YES' if the test ran correctly, else 'NO'.

    A passed test is awarded its points (>0) and reports an "OK"/"corect"
    message; failures ("Time limit exceeded", "Raspuns gresit", "Killed ...",
    memory limits, etc.) score 0. We accept either signal so a hypothetical
    correct-but-zero-point test is still counted as OK.
    """
    if _to_int(points) > 0:
        return "YES"
    m = (message or "").strip().lower()
    if "corect" in m or m in ("ok", "ok!"):
        return "YES"
    return "NO"


def parse_job_detail(page_html):
    """Parse the per-test evaluation report of a job_detail page.

    Returns a list of dicts, one per test:
        {test, subtask, time, memory, message, ok, subtask_points}
    where `ok` is "YES"/"NO" for whether the test ran correctly.

    Subtask numbering (a subtask is one independently-scored group of tests):
    - Grouped problems (a "Punctaj/grupa" column is present): a new subtask
      starts on every row that carries the extra group-score cell; every test
      in that group shares the group's awarded score as `subtask_points`.
    - Ungrouped problems: each test is scored on its own, so every test is its
      own subtask (1, 2, 3, ...) and `subtask_points` is that test's points.
      This matches how single-test groups already number in the grouped case.

    An empty list is returned when there is no test table (e.g. a compile
    error or a submission still being evaluated).
    """
    tbl = EVAL_TABLE_RE.search(page_html)
    if not tbl:
        return []
    table = tbl.group(1)
    grouped = "Punctaj/grupa" in table
    tbody = EVAL_TBODY_RE.search(table)
    body = tbody.group(1) if tbody else table

    tests = []
    subtask = 0
    group_points = ""
    for row in EVAL_ROW_RE.findall(body):
        if "colspan" in row:          # the trailing "Punctaj total" summary row
            continue
        cells = EVAL_CELL_RE.findall(row)
        if len(cells) < 5:            # header row or something unexpected
            continue
        points = _cell_text(cells[4])
        message = _cell_text(cells[3])
        if grouped:
            if len(cells) >= 6:       # first test of a new group carries its score
                subtask += 1
                group_points = _cell_text(cells[5])
            sub_points = group_points
        else:
            subtask += 1              # ungrouped: each test is its own subtask
            sub_points = points       # ... scored on its own
        tests.append({
            "test":           _cell_text(cells[0]),
            "subtask":        subtask,
            "time":           _cell_text(cells[1]),
            "memory":         _cell_text(cells[2]),
            "message":        message,
            "ok":             _test_ok(message, points),
            "subtask_points": sub_points,
        })
    return tests


def fetch_job_detail(job_id):
    """Fetch a job_detail page's HTML (the evaluation report)."""
    return get(f"{JOB}/{job_id}")


DETAIL_FIELDS = ["submission_id", "test", "subtask", "time", "memory",
                 "message", "ok", "subtask_points"]


def save_details(row, details_dir):
    """Fetch and write one submission's per-test report to details/<id>.csv.

    Annotates the row with num_tests and num_subtasks. Returns (path, fetched)
    where `fetched` is True when a network request was made (so the caller can
    apply the politeness delay). Existing files are kept (resume-friendly).
    """
    job_id = row["id"]
    path = os.path.join(details_dir, f"{job_id}.csv")
    if os.path.exists(path):
        return path, False
    try:
        page = fetch_job_detail(job_id)
    except Exception as e:
        print(f"    ! detail {job_id}: {e}", file=sys.stderr)
        return "", True

    tests = parse_job_detail(page)
    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=DETAIL_FIELDS)
        w.writeheader()
        for t in tests:
            w.writerow({"submission_id": job_id, **t})

    row["num_tests"] = len(tests)
    row["num_subtasks"] = len({t["subtask"] for t in tests})
    return path, True


# --- problem statement: "Indicatii de rezolvare" (solution hints) -----------

# The heading may be written with or without Romanian diacritics, e.g.
# "Indicatii", "Indicaţii" (t-cedilla) or "Indicații" (t-comma); it may be any
# heading level (seen as both <h2> and <h3>) and may carry attributes.
INDICATII_RE = re.compile(
    r'<h[1-6][^>]*>\s*Indica[tţț]ii\s+de\s+rezolvare\s*</h[1-6]>', re.I)
HEADING_RE   = re.compile(r'<h[1-6][\s>]', re.I)
LINK_RE      = re.compile(r'<a\s+[^>]*href="([^"]+)"[^>]*>(.*?)</a>', re.S)
BR_RE        = re.compile(r'<br\s*/?>', re.I)
BLOCK_RE     = re.compile(r'</?(?:p|div|li|ul|ol|h[1-6]|pre|table|tr|blockquote)[^>]*>', re.I)
BLANKS_RE    = re.compile(r'\n{3,}')

# Where the hints section ends: whichever of these comes first after the
# heading. The next heading of any level is handled separately (HEADING_RE).
_END_MARKERS = ('<div class="macroMessage"', '<div id="comentarii"',
                '<p><a href="/documentatie/tutorial"')


def _abs_url(u):
    u = html.unescape(u.strip())
    return SITE + u if u.startswith("/") else u


def _html_to_text(fragment):
    """Turn a statement HTML fragment into readable plain text.

    Links are kept as 'text (absolute-url)' so references to example sources
    (e.g. '/job_detail/143144?action=view-source') survive.
    """
    text = LINK_RE.sub(
        lambda m: f"{_cell_text(m.group(2))} ({_abs_url(m.group(1))})", fragment)
    text = BR_RE.sub("\n", text)
    text = BLOCK_RE.sub("\n", text)
    text = TAG_RE.sub("", text)
    text = html.unescape(text)
    lines = [ln.strip() for ln in text.splitlines()]
    return BLANKS_RE.sub("\n\n", "\n".join(lines)).strip()


def extract_indicatii(page_html):
    """Return the 'Indicatii de rezolvare' text of a problem page, or None."""
    m = INDICATII_RE.search(page_html)
    if not m:
        return None
    start = m.end()
    end = len(page_html)
    nxt = HEADING_RE.search(page_html, start)   # next heading of any level
    if nxt:
        end = nxt.start()
    for marker in _END_MARKERS:
        i = page_html.find(marker, start)
        if i != -1:
            end = min(end, i)
    text = _html_to_text(page_html[start:end])
    return text or None


def fetch_problem_page(task):
    return get(f"{PROB}/{task}")


def save_solution(task, out_dir):
    """Write the problem's solution hints to out_dir.

    - Found  -> 'solution.txt' with the hints (and the problem URL header).
    - Missing-> 'solution_MISSING.txt' recording only the link, so problems
      lacking hints are easy to spot (e.g. `find . -name solution_MISSING.txt`).

    A hand-added 'solution.txt' (e.g. copied from GitHub later) always takes
    priority: if one already exists it is never overwritten, and no stale
    'solution_MISSING.txt' is left beside it. Whenever a solution.txt is present
    the (now wrong) 'solution_MISSING.txt' marker is removed.

    Returns (path, found).
    """
    url = f"{PROB}/{task}"
    sol_path = os.path.join(out_dir, "solution.txt")
    missing_path = os.path.join(out_dir, "solution_MISSING.txt")

    # Respect an existing (possibly hand-written) solution.txt: keep it as-is.
    if os.path.isfile(sol_path):
        if os.path.exists(missing_path):
            os.remove(missing_path)
        return sol_path, True

    try:
        text = extract_indicatii(fetch_problem_page(task))
    except Exception as e:
        print(f"    ! solution {task}: {e}", file=sys.stderr)
        text = None

    if text:
        body = f"# Indicatii de rezolvare - {task}\n# {url}\n\n{text}\n"
        with open(sol_path, "w", encoding="utf-8") as f:
            f.write(body)
        if os.path.exists(missing_path):    # drop a previous 'missing' marker
            os.remove(missing_path)
        return sol_path, True

    body = (f"# NO 'Indicatii de rezolvare' for problem '{task}'\n# {url}\n")
    with open(missing_path, "w", encoding="utf-8") as f:
        f.write(body)
    return missing_path, False


def first(rx, text, group=1, default=""):
    m = rx.search(text)
    return html.unescape(m.group(group).strip()) if m else default


def parse_score(status):
    """Extract numeric points from a status string, or None."""
    m = re.search(r'(\d+)\s*puncte', status)
    return int(m.group(1)) if m else None


def parse_rows(page_html):
    rows = []
    for block in ROW_RE.findall(page_html):
        status = first(STATUS_RE, block)
        rows.append({
            "id":        first(ID_RE, block),
            "user":      first(USER_RE, block, 1),
            "full_name": first(FULLNM_RE, block) or first(USER_RE, block, 2),
            "problem":   first(PROB_RE, block, 1),
            "size":      first(SIZE_RE, block),
            "date":      first(DATE_RE, block),
            "score":     parse_score(status),
            "status":    status,
            "url":       f"https://www.infoarena.ro/job_detail/{first(ID_RE, block)}",
        })
    return rows


def save_source(row, code_dir, keep_langs=None):
    """Download and save one submission's source.

    Records row["compiler"] and row["language"]. If keep_langs is given (a set
    of language families) and this submission's language is not in it, the file
    is NOT written (dropped by the filter) but the row is still annotated.

    Returns (source_file, fetched) where `fetched` is True when a network
    request was made (so the caller knows whether to apply the politeness delay).
    """
    job_id = row["id"]
    row["_missing"] = False               # code is available unless proven otherwise
    # Resume: a file for this id already exists -> read language from its extension.
    for name in os.listdir(code_dir):
        if name.startswith(job_id + "."):
            ext = name.rsplit(".", 1)[-1]
            row["language"] = _EXT_LANG.get(ext, "unknown")
            return name, False
    try:
        code, comp = fetch_source(job_id)
    except Exception as e:
        print(f"    ! source {job_id}: {e}", file=sys.stderr)
        row["_missing"] = True
        return "", True
    if code is None:
        # No accessible source: the author/site hides it (login wall, no cookie).
        print(f"    ! source {job_id}: not available", file=sys.stderr)
        row["_missing"] = True
        return "", True

    lang, ext = classify(comp)
    row["compiler"] = comp
    row["language"] = lang
    if lang == "unknown":
        print(f"    ? source {job_id}: unknown compiler-id '{comp}' -> saved as .txt",
              file=sys.stderr)

    if keep_langs is not None and lang not in keep_langs:
        return "", True                    # dropped by language filter (code exists)

    fname = f"{job_id}.{ext}"
    with open(os.path.join(code_dir, fname), "w", encoding="utf-8") as f:
        f.write(code)
    return fname, True


def scrape(task, max_pages=None, code_dir=None, keep_langs=None, details_dir=None,
           drop_missing_code=False):
    all_rows = []
    first_entry = 0
    page = 0
    while True:
        page += 1
        if max_pages and page > max_pages:
            break
        page_html = fetch(task, first_entry)
        rows = parse_rows(page_html)
        if not rows:
            break
        all_rows.extend(rows)
        print(f"  page {page}: +{len(rows)} rows (total {len(all_rows)})", file=sys.stderr)

        if code_dir:
            for row in rows:
                fname, fetched = save_source(row, code_dir, keep_langs)
                row["source_file"] = fname
                if fetched:
                    time.sleep(DELAY)      # be polite: one request per source

        if details_dir:
            for row in rows:
                _, fetched = save_details(row, details_dir)
                if fetched:
                    time.sleep(DELAY)      # be polite: one request per report

        if len(rows) < PAGE_SIZE:
            break            # last page
        first_entry += PAGE_SIZE
        time.sleep(DELAY)

    if code_dir and drop_missing_code:
        kept = []
        removed = 0
        for r in all_rows:
            if r.get("_missing"):
                removed += 1
                if details_dir:              # keep details/ in sync with the CSV
                    dpath = os.path.join(details_dir, f"{r['id']}.csv")
                    if os.path.exists(dpath):
                        os.remove(dpath)
            else:
                kept.append(r)
        if removed:
            print(f"  dropped {removed} submissions with no accessible source",
                  file=sys.stderr)
        all_rows = kept
    for r in all_rows:                       # strip the private bookkeeping key
        r.pop("_missing", None)
    return all_rows


def main():
    ap = argparse.ArgumentParser(description="Scrape infoarena submissions for a problem.")
    ap.add_argument("task", help="problem slug, e.g. cmlsc")
    ap.add_argument("-o", "--output", help="output CSV file (default: <task>.csv)")
    ap.add_argument("--max-pages", type=int, help="limit number of pages (debug)")
    ap.add_argument("--code", action="store_true",
                    help="also download each submission's source code")
    ap.add_argument("--code-dir",
                    help="directory for downloaded sources (default: <task>_sources)")
    ap.add_argument("--keep-missing", action="store_true",
                    help="with --code, keep submissions whose source is not "
                         "accessible (default: drop them from the CSV)")
    ap.add_argument("--details", action="store_true",
                    help="also parse each job_detail page and write a per-test "
                         "CSV to the details directory")
    ap.add_argument("--details-dir",
                    help="directory for per-submission detail CSVs (default: <task>_details)")
    ap.add_argument("--solution", action="store_true",
                    help="also save the problem's 'Indicatii de rezolvare' hints to "
                         "solution.txt (or solution_MISSING.txt if there are none), "
                         "next to the output CSV")
    ap.add_argument("--langs",
                    help="only save sources in these languages, comma-separated "
                         "(e.g. 'c,cpp,rust,python'). Others are skipped but still "
                         "listed in the CSV with their detected language.")
    ap.add_argument("--cookie",
                    help="infoarena session cookie (or set INFOARENA_COOKIE) to also "
                         "fetch login-gated sources. Copy the 'Cookie' request header "
                         "from your logged-in browser's DevTools.")
    args = ap.parse_args()

    if args.cookie:
        globals()["COOKIE"] = args.cookie

    out = args.output or f"{args.task}.csv"
    keep_langs = parse_langs(args.langs)
    code_dir = None
    if args.code:
        code_dir = args.code_dir or f"{args.task}_sources"
        os.makedirs(code_dir, exist_ok=True)
    details_dir = None
    if args.details:
        details_dir = args.details_dir or f"{args.task}_details"
        os.makedirs(details_dir, exist_ok=True)

    print(f"Scraping submissions for '{args.task}' ...", file=sys.stderr)
    if keep_langs:
        print(f"  language filter: keeping {sorted(keep_langs)}", file=sys.stderr)
    rows = scrape(args.task, args.max_pages, code_dir, keep_langs, details_dir,
                  drop_missing_code=not args.keep_missing)

    fields = ["id", "user", "full_name", "problem", "size", "date", "score",
              "status", "language", "compiler", "source_file",
              "num_tests", "num_subtasks", "url"]
    for r in rows:                       # ensure every row has all keys
        r.setdefault("language", "")
        r.setdefault("compiler", "")
        r.setdefault("source_file", "")
        r.setdefault("num_tests", "")
        r.setdefault("num_subtasks", "")
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=fields)
        w.writeheader()
        w.writerows(rows)
    print(f"Done: {len(rows)} submissions written to {out}", file=sys.stderr)

    if args.solution:
        sol_dir = os.path.dirname(os.path.abspath(out)) or "."
        path, found = save_solution(args.task, sol_dir)
        tag = "hints" if found else "MISSING"
        print(f"Solution ({tag}) -> {path}", file=sys.stderr)


if __name__ == "__main__":
    main()
