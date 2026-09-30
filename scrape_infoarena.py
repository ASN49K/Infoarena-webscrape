#!/usr/bin/env python3

import argparse
import csv
import html
import json
import os
import re
import sys
import time
import urllib.parse
import urllib.request

BASE = "https://www.infoarena.ro/monitor"
JOB = "https://www.infoarena.ro/job_detail"
PROB = "https://www.infoarena.ro/problema"
SITE = "https://www.infoarena.ro"
PAGE_SIZE = 250
DELAY = 0.01
UA = "Mozilla/5.0 (compatible; infoarena-scraper/1.0)"

COOKIE = os.environ.get("INFOARENA_COOKIE", "")

REFETCH_KINDS = ("code", "details", "json", "problem-json", "solution",
                 "statement", "attachments")
REFETCH = set()


def refetching(kind):
    return kind in REFETCH

ROW_RE = re.compile(r'<tr class="(?:odd|even)">(.*?)</tr>', re.S)

ID_RE = re.compile(r'/job_detail/(\d+)">#\d+')
USER_RE = re.compile(r'<span class="username"><a href="[^"]*/utilizator/([^"]+)">([^<]*)</a>')
FULLNM_RE = re.compile(r'/utilizator/[^"]+"><img[^>]*/>([^<]*)</a>')
PROB_RE = re.compile(r'/problema/([^"]+)">([^<]*)</a>')
ROUND_RE = re.compile(r'<td ><a href="/([^"]+)">([^<]*)</a></td>\s*<td ><a href="/job_detail/\d+\?action=view-source">')
SIZE_RE = re.compile(r'action=view-source">([^<]*)</a></td>')
DATE_RE = re.compile(r'</a></td>\s*<td >([^<]*)</td>\s*<td ><a href="/job_detail/\d+"><span')
STATUS_RE = re.compile(r'<span class="job-status-[^"]*">([^<]*)</span>')

CODE_RE = re.compile(r'<div class="code"><pre><code>(.*?)</code></pre>', re.S)
COMPILER_RE = re.compile(r'<td class="compiler-id">([^<]*)</td>')

EVAL_TABLE_RE = re.compile(r'<table class="job-eval-tests">(.*?)</table>', re.S)
EVAL_TBODY_RE = re.compile(r'<tbody>(.*?)</tbody>', re.S)
EVAL_ROW_RE = re.compile(r'<tr[^>]*>(.*?)</tr>', re.S)
EVAL_CELL_RE = re.compile(r'<td[^>]*>(.*?)</td>', re.S)
TAG_RE = re.compile(r'<[^>]+>')

_LANG_RULES = [
    ("cpp", ("cpp", "cpp")),
    ("gpp", ("cpp", "cpp")),
    ("g++", ("cpp", "cpp")),
    ("c-", ("c", "c")),
    ("gcc", ("c", "c")),
    ("fpc", ("pascal", "pas")),
    ("pascal", ("pascal", "pas")),
    ("rs", ("rust", "rs")),
    ("rust", ("rust", "rs")),
    ("py", ("python", "py")),
    ("python", ("python", "py")),
    ("java", ("java", "java")),
    ("kotlin", ("kotlin", "kt")),
    ("dotnet", ("csharp", "cs")),
    ("cs", ("csharp", "cs")),
    ("csharp", ("csharp", "cs")),
    ("go", ("go", "go")),
    ("js", ("javascript", "js")),
    ("node", ("javascript", "js")),
]


def classify(compiler_id):
    cid = (compiler_id or "").strip().lower()
    if cid == "c":
        return ("c", "c")
    for prefix, res in _LANG_RULES:
        if cid.startswith(prefix):
            return res
    return ("unknown", "txt")


_EXT_LANG = {"cpp": "cpp", "c": "c", "pas": "pascal", "rs": "rust", "py": "python",
             "java": "java", "kt": "kotlin", "cs": "csharp", "go": "go", "js": "javascript"}

DEFAULT_LANGS = {"c", "cpp", "java"}

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
    if not spec:
        return set(DEFAULT_LANGS)
    if spec.strip().lower() == "all":
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
    return html.unescape(TAG_RE.sub("", raw)).strip()


def _to_int(s):
    m = re.search(r'-?\d+', s or "")
    return int(m.group()) if m else 0


CORECT_RE = re.compile(r"\bcorect\b")


def _test_ok(message, points):
    if _to_int(points) > 0:
        return "YES"
    m = (message or "").strip().lower()
    if CORECT_RE.search(m) or m in ("ok", "ok!"):
        return "YES"
    return "NO"


def parse_job_detail(page_html):
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
        if "colspan" in row:
            continue
        cells = EVAL_CELL_RE.findall(row)
        if len(cells) < 5:
            continue
        points = _cell_text(cells[4])
        message = _cell_text(cells[3])
        if grouped:
            if len(cells) >= 6:
                subtask += 1
                group_points = _cell_text(cells[5])
            sub_points = group_points
        else:
            subtask += 1
            sub_points = points
        tests.append({
            "test": _cell_text(cells[0]),
            "subtask": subtask,
            "time": _cell_text(cells[1]),
            "memory": _cell_text(cells[2]),
            "message": message,
            "ok": _test_ok(message, points),
            "test_points": points,
            "subtask_points": sub_points,
        })
    return tests


def fetch_job_detail(job_id):
    return get(f"{JOB}/{job_id}")


DETAIL_FIELDS = ["submission_id", "test", "subtask", "time", "memory",
                 "message", "ok", "test_points", "subtask_points"]


def save_details(row, details_dir):
    job_id = row["id"]
    path = os.path.join(details_dir, f"{job_id}.csv")
    if os.path.exists(path) and not refetching("details"):
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


_UNSAFE_NAME_RE = re.compile(r'[^A-Za-z0-9._-]')


def _safe_name(name):
    return _UNSAFE_NAME_RE.sub("_", name or "")


def _read_code_file(code_dir, job_id, code_index=None):
    if not code_dir:
        return None
    name = (code_index if code_index is not None else index_code_dir(code_dir)).get(job_id)
    if not name:
        return None
    try:
        with open(os.path.join(code_dir, name), encoding="utf-8",
                  errors="replace") as f:
            return f.read()
    except OSError:
        return None


def _read_details_json(details_dir, job_id):
    if not details_dir:
        return []
    path = os.path.join(details_dir, f"{job_id}.csv")
    if not os.path.isfile(path):
        return []
    with open(path, newline="", encoding="utf-8") as f:
        rows = list(csv.DictReader(f))

    legacy = bool(rows) and "test_points" not in rows[0]
    subtasks = [r.get("subtask") for r in rows]
    recoverable = len(set(subtasks)) == len(subtasks)

    tests = []
    for r in rows:
        if not legacy:
            test_points = _to_int(r.get("test_points"))
        elif recoverable:
            test_points = _to_int(r.get("subtask_points"))
        else:
            test_points = None
        tests.append({
            "test": _to_int(r.get("test")),
            "subtask": _to_int(r.get("subtask")),
            "time": r.get("time", ""),
            "memory": r.get("memory", ""),
            "message": r.get("message", ""),
            "ok": r.get("ok", "") == "YES",
            "test_points": test_points,
            "subtask_points": _to_int(r.get("subtask_points")),
        })
    return tests


def save_submission_json(row, submissions_dir, code_dir, details_dir, code_index=None):
    job_id = row["id"]
    path = os.path.join(submissions_dir, f"{_safe_name(row.get('user'))}_{job_id}.json")
    if os.path.isfile(path) and not refetching("json"):
        return path, False
    code = _read_code_file(code_dir, job_id, code_index)
    if code is None:
        return "", False
    data = {
        "id": job_id,
        "user": row.get("user", ""),
        "full_name": row.get("full_name", ""),
        "problem": row.get("problem", ""),
        "score": row.get("score"),
        "status": row.get("status", ""),
        "language": row.get("language", ""),
        "compiler": row.get("compiler", ""),
        "size": row.get("size", ""),
        "submitted_at": row.get("date", ""),
        "url": row.get("url", ""),
        "code": code,
        "tests": _read_details_json(details_dir, job_id),
    }
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)
    return path, True


def load_prior_rows(csv_path):
    prior = {}
    if csv_path and os.path.isfile(csv_path):
        with open(csv_path, newline="", encoding="utf-8") as f:
            for r in csv.DictReader(f):
                if r.get("id"):
                    prior[r["id"]] = r
    return prior


INDICATII_RE = re.compile(
    r'<h[1-6][^>]*>\s*Indica[tţț]ii\s+de\s+rezolvare\s*</h[1-6]>', re.I)
HEADING_RE = re.compile(r'<h[1-6][\s>]', re.I)
TITLE_RE = re.compile(r'<h1[^>]*>(?!\s*<a\s+href="/")(.*?)</h1>', re.S | re.I)
STATEMENT_END_RE = re.compile(
    r'<h[1-6][^>]*>\s*(?:Indica[tţț]ii\b|Rezolvare\b'
    r'|Probleme\s+(?:similare|asem[aă]n[aă]toare))', re.I)
LINK_RE = re.compile(r'<a\s+[^>]*href="([^"]+)"[^>]*>(.*?)</a>', re.S)
BR_RE = re.compile(r'<br\s*/?>', re.I)
BLOCK_RE = re.compile(r'</?(?:p|div|li|ul|ol|h[1-6]|pre|table|tr|td|th|blockquote)[^>]*>', re.I)
BLANKS_RE = re.compile(r'\n{3,}')

TIME_LIMIT_RE = re.compile(r'Timp\s+execu[^<]*</strong></td>\s*<td>([^<]*)</td>', re.I)
MEM_LIMIT_RE = re.compile(r'Limit[^<]*de\s+memorie</strong></td>\s*<td>([^<]*)</td>', re.I)
EXAMPLE_RE = re.compile(r'<table\s+class="example"[^>]*>(.*?)</table>', re.S | re.I)
SECTION_HEAD_RE = re.compile(r'<h([2-6])[^>]*>(.*?)</h\1>', re.S | re.I)
EX_ROW_RE = re.compile(r'<tr[^>]*>(.*?)</tr>', re.S | re.I)
EX_CELL_RE = re.compile(r'<td[^>]*>(.*?)</td>', re.S | re.I)

_DIACRITICS = str.maketrans({
    'ă': 'a', 'â': 'a', 'î': 'i', 'ș': 's', 'ş': 's', 'ț': 't', 'ţ': 't',
    'Ă': 'a', 'Â': 'a', 'Î': 'i', 'Ș': 's', 'Ş': 's', 'Ț': 't', 'Ţ': 't'})

_END_MARKERS = ('<div class="macroMessage"', '<div id="comentarii"',
                '<p><a href="/documentatie/tutorial"')


def _abs_url(u):
    u = html.unescape(u.strip())
    return SITE + u if u.startswith("/") else u


def _html_to_text(fragment):
    text = LINK_RE.sub(
        lambda m: f"{_cell_text(m.group(2))} ({_abs_url(m.group(1))})", fragment)
    text = BR_RE.sub("\n", text)
    text = BLOCK_RE.sub("\n", text)
    text = TAG_RE.sub("", text)
    text = html.unescape(text)
    lines = [ln.strip() for ln in text.splitlines()]
    return BLANKS_RE.sub("\n\n", "\n".join(lines)).strip()


def extract_indicatii(page_html):
    m = INDICATII_RE.search(page_html)
    if not m:
        return None
    start = m.end()
    end = len(page_html)
    nxt = HEADING_RE.search(page_html, start)
    if nxt:
        end = nxt.start()
    for marker in _END_MARKERS:
        i = page_html.find(marker, start)
        if i != -1:
            end = min(end, i)
    text = _html_to_text(page_html[start:end])
    return text or None


def extract_statement(page_html):
    m = TITLE_RE.search(page_html)
    if not m:
        return None
    title = _cell_text(m.group(1))
    start = m.end()
    end = len(page_html)
    tail = STATEMENT_END_RE.search(page_html, start)
    if tail:
        end = tail.start()
    for marker in _END_MARKERS:
        i = page_html.find(marker, start)
        if i != -1:
            end = min(end, i)
    body = _html_to_text(page_html[start:end])
    if not body:
        return None
    return f"{title}\n\n{body}" if title else body


_PAGE_CACHE = {}


def fetch_problem_page(task):
    if task not in _PAGE_CACHE:
        _PAGE_CACHE[task] = get(f"{PROB}/{task}")
    return _PAGE_CACHE[task]


def _norm_heading(raw):
    return _cell_text(raw).lower().translate(_DIACRITICS)


def _cell_multiline(raw):
    text = html.unescape(TAG_RE.sub("", BR_RE.sub("\n", raw)))
    return "\n".join(ln.rstrip() for ln in text.splitlines() if ln.strip()).strip()


def extract_example(page_html):
    m = EXAMPLE_RE.search(page_html)
    if not m:
        return "", ""
    ins, outs = [], []
    for row in EX_ROW_RE.findall(m.group(1)):
        cells = EX_CELL_RE.findall(row)
        if len(cells) >= 2:
            ins.append(_cell_multiline(cells[0]))
            outs.append(_cell_multiline(cells[1]))
    return "\n\n".join(ins).strip(), "\n\n".join(outs).strip()


def _sections(page_html, start):
    heads = list(SECTION_HEAD_RE.finditer(page_html, start))
    out = []
    for i, m in enumerate(heads):
        end = heads[i + 1].start() if i + 1 < len(heads) else len(page_html)
        out.append((_norm_heading(m.group(2)), page_html[m.end():end]))
    return out


def extract_problem(page_html, task):
    tm = TITLE_RE.search(page_html)
    title = _cell_text(tm.group(1)) if tm else ""
    body_start = tm.end() if tm else 0

    sections = _sections(page_html, body_start)
    first_head = SECTION_HEAD_RE.search(page_html, body_start)
    intro = _html_to_text(page_html[body_start:first_head.start()]) if first_head else ""

    def section(*keys):
        for name, body in sections:
            if any(k in name for k in keys):
                return _html_to_text(body)
        return ""

    cerinta = section("cerint")
    statement = f"{intro}\n\n{cerinta}".strip() if (intro and cerinta) else (intro or cerinta)
    sample_in, sample_out = extract_example(page_html)

    return {
        "problem": task,
        "title": title,
        "url": f"{PROB}/{task}",
        "time_limit": first(TIME_LIMIT_RE, page_html),
        "memory_limit": first(MEM_LIMIT_RE, page_html),
        "statement": statement,
        "input_format": section("intrare"),
        "output_format": section("iesire"),
        "constraints": section("restrict"),
        "sample_input": sample_in,
        "sample_output": sample_out,
    }


def save_problem_json(task, out_dir):
    path = os.path.join(out_dir, f"{task}.json")
    if os.path.isfile(path) and not refetching("problem-json"):
        return path, True
    try:
        data = extract_problem(fetch_problem_page(task), task)
    except Exception as e:
        print(f"    ! problem-json {task}: {e}", file=sys.stderr)
        return "", False
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, ensure_ascii=False, indent=2)
    return path, True


def save_solution(task, out_dir):
    url = f"{PROB}/{task}"
    sol_path = os.path.join(out_dir, "solution.txt")
    missing_path = os.path.join(out_dir, "solution_MISSING.txt")

    if os.path.isfile(sol_path) and not refetching("solution"):
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
        if os.path.exists(missing_path):
            os.remove(missing_path)
        return sol_path, True

    body = (f"# NO 'Indicatii de rezolvare' for problem '{task}'\n# {url}\n")
    with open(missing_path, "w", encoding="utf-8") as f:
        f.write(body)
    return missing_path, False


def save_statement(task, out_dir):
    url = f"{PROB}/{task}"
    st_path = os.path.join(out_dir, "statement.txt")
    missing_path = os.path.join(out_dir, "statement_MISSING.txt")

    if os.path.isfile(st_path) and not refetching("statement"):
        if os.path.exists(missing_path):
            os.remove(missing_path)
        return st_path, True

    try:
        text = extract_statement(fetch_problem_page(task))
    except Exception as e:
        print(f"    ! statement {task}: {e}", file=sys.stderr)
        text = None

    if text:
        body = f"# Statement - {task}\n# {url}\n\n{text}\n"
        with open(st_path, "w", encoding="utf-8") as f:
            f.write(body)
        if os.path.exists(missing_path):
            os.remove(missing_path)
        return st_path, True

    body = (f"# NO statement parsed for problem '{task}'\n# {url}\n")
    with open(missing_path, "w", encoding="utf-8") as f:
        f.write(body)
    return missing_path, False


def first(rx, text, group=1, default=""):
    m = rx.search(text)
    return html.unescape(m.group(group).strip()) if m else default


def parse_score(status):
    m = re.search(r'(\d+)\s*puncte', status)
    return int(m.group(1)) if m else None


def parse_rows(page_html):
    rows = []
    for block in ROW_RE.findall(page_html):
        status = first(STATUS_RE, block)
        rows.append({
            "id": first(ID_RE, block),
            "user": first(USER_RE, block, 1),
            "full_name": first(FULLNM_RE, block) or first(USER_RE, block, 2),
            "problem": first(PROB_RE, block, 1),
            "size": first(SIZE_RE, block),
            "date": first(DATE_RE, block),
            "score": parse_score(status),
            "status": status,
            "url": f"https://www.infoarena.ro/job_detail/{first(ID_RE, block)}",
        })
    return rows


def index_code_dir(code_dir):
    idx = {}
    if code_dir and os.path.isdir(code_dir):
        for name in os.listdir(code_dir):
            idx.setdefault(name.split(".", 1)[0], name)
    return idx


def save_source(row, code_dir, keep_langs=None, prior=None, code_index=None):
    job_id = row["id"]
    row["_missing"] = False
    if code_index is None:
        code_index = index_code_dir(code_dir)
    existing = code_index.get(job_id)
    if existing and not refetching("code"):
        ext = existing.rsplit(".", 1)[-1]
        row["language"] = _EXT_LANG.get(ext, "unknown")
        was = (prior or {}).get(job_id)
        if was:
            row["compiler"] = was.get("compiler", "")
            if was.get("language"):
                row["language"] = was["language"]
        return existing, False
    try:
        code, comp = fetch_source(job_id)
    except Exception as e:
        print(f"    ! source {job_id}: {e}", file=sys.stderr)
        row["_missing"] = True
        return "", True
    if code is None:
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
        return "", True

    fname = f"{job_id}.{ext}"
    if existing and existing != fname:
        try:
            os.remove(os.path.join(code_dir, existing))
        except OSError:
            pass
    with open(os.path.join(code_dir, fname), "w", encoding="utf-8") as f:
        f.write(code)
    code_index[job_id] = fname
    return fname, True


def scrape(task, max_pages=None, code_dir=None, keep_langs=None, details_dir=None,
           drop_missing_code=False, submissions_dir=None, prior=None):
    all_rows = []
    first_entry = 0
    page = 0
    code_index = index_code_dir(code_dir) if code_dir else None
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
                fname, fetched = save_source(row, code_dir, keep_langs, prior, code_index)
                row["source_file"] = fname
                if fetched:
                    time.sleep(DELAY)

        if details_dir:
            for row in rows:
                _, fetched = save_details(row, details_dir)
                if fetched:
                    time.sleep(DELAY)

        if submissions_dir:
            for row in rows:
                save_submission_json(row, submissions_dir, code_dir, details_dir, code_index)

        if len(rows) < PAGE_SIZE:
            break
        first_entry += PAGE_SIZE
        time.sleep(DELAY)

    if code_dir and drop_missing_code:
        kept = []
        removed = 0
        for r in all_rows:
            if r.get("_missing"):
                removed += 1
                if details_dir:
                    dpath = os.path.join(details_dir, f"{r['id']}.csv")
                    if os.path.exists(dpath):
                        os.remove(dpath)
            else:
                kept.append(r)
        if removed:
            print(f"  dropped {removed} submissions with no accessible source",
                  file=sys.stderr)
        all_rows = kept
    for r in all_rows:
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
    ap.add_argument("--statement", action="store_true",
                    help="also save the problem's statement (Cerinta, I/O format, "
                         "restrictions and example) to statement.txt (or "
                         "statement_MISSING.txt if it can't be parsed), next to the "
                         "output CSV")
    ap.add_argument("--json", action="store_true",
                    help="also write one JSON file per submission "
                         "(<username>_<id>.json, with code + score + compiler + "
                         "time + per-test report) to the submissions directory. "
                         "Built from already-downloaded sources/details, so it "
                         "adds no network requests. Implies --code and --details.")
    ap.add_argument("--submissions-dir",
                    help="directory for per-submission JSON (default: <task>_submissions)")
    ap.add_argument("--problem-json", action="store_true",
                    help="also save the problem's structured metadata (statement, "
                         "I/O format, time/memory limits, sample I/O) to "
                         "<task>.json, next to the output CSV")
    ap.add_argument("--langs",
                    help="only save sources in these languages, comma-separated "
                         "(e.g. 'c,cpp,rust,python'). Others are skipped but still "
                         "listed in the CSV with their detected language. "
                         "Defaults to 'c,cpp,java'; pass 'all' to save every language.")
    ap.add_argument("--cookie",
                    help="infoarena session cookie (or set INFOARENA_COOKIE) to also "
                         "fetch login-gated sources. Copy the 'Cookie' request header "
                         "from your logged-in browser's DevTools.")
    args = ap.parse_args()

    if args.cookie:
        globals()["COOKIE"] = args.cookie

    out = args.output or f"{args.task}.csv"
    keep_langs = parse_langs(args.langs)
    want_code = args.code or args.json
    want_details = args.details or args.json
    code_dir = None
    if want_code:
        code_dir = args.code_dir or f"{args.task}_sources"
        os.makedirs(code_dir, exist_ok=True)
    details_dir = None
    if want_details:
        details_dir = args.details_dir or f"{args.task}_details"
        os.makedirs(details_dir, exist_ok=True)
    submissions_dir = None
    if args.json:
        submissions_dir = args.submissions_dir or f"{args.task}_submissions"
        os.makedirs(submissions_dir, exist_ok=True)

    print(f"Scraping submissions for '{args.task}' ...", file=sys.stderr)
    if keep_langs:
        print(f"  language filter: keeping {sorted(keep_langs)}", file=sys.stderr)
    prior = load_prior_rows(out)
    rows = scrape(args.task, args.max_pages, code_dir, keep_langs, details_dir,
                  drop_missing_code=not args.keep_missing,
                  submissions_dir=submissions_dir, prior=prior)

    fields = ["id", "user", "full_name", "problem", "size", "date", "score",
              "status", "language", "compiler", "source_file",
              "num_tests", "num_subtasks", "url"]
    for r in rows:
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

    if args.statement:
        st_dir = os.path.dirname(os.path.abspath(out)) or "."
        path, found = save_statement(args.task, st_dir)
        tag = "statement" if found else "MISSING"
        print(f"Statement ({tag}) -> {path}", file=sys.stderr)

    if args.json:
        print(f"Submissions JSON -> {submissions_dir}/", file=sys.stderr)

    if args.problem_json:
        pj_dir = os.path.dirname(os.path.abspath(out)) or "."
        path, ok = save_problem_json(args.task, pj_dir)
        print(f"Problem JSON ({'ok' if ok else 'FAILED'}) -> {path}", file=sys.stderr)


if __name__ == "__main__":
    main()
