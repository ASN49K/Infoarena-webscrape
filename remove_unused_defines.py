#!/usr/bin/env python3

import argparse
import json
import os
import re
import shutil
import sys

C_EXTS = {".c", ".cpp", ".cc", ".cxx", ".c++", ".h", ".hpp", ".hh", ".hxx", ".inl"}


def _raw_prefix_ok(text, r_index):
    start = r_index
    for pre in ("u8", "u", "U", "L", ""):
        if text[r_index - len(pre):r_index] == pre:
            start = r_index - len(pre)
            break
    if start > 0:
        prev = text[start - 1]
        if prev.isalnum() or prev == "_":
            return False
    return True


def _scan_segments(text, keep_comments):
    segs = []
    buf = []

    def flush():
        if buf:
            segs.append(("code", "".join(buf)))
            buf.clear()

    i, n = 0, len(text)
    while i < n:
        c = text[i]

        if c == '"':
            if i > 0 and text[i - 1] == "R" and _raw_prefix_ok(text, i - 1):
                k = i + 1
                while k < n and text[k] not in '()\\ \t\r\n"':
                    k += 1
                if k < n and text[k] == "(":
                    close = ")" + text[i + 1:k] + '"'
                    end = text.find(close, k + 1)
                    end = n if end == -1 else end + len(close)
                    flush()
                    segs.append(("literal", text[i:end]))
                    i = end
                    continue
            j = i + 1
            while j < n:
                d = text[j]
                if d == "\\":
                    j += 2
                    continue
                if d == '"':
                    j += 1
                    break
                if d == "\n":
                    break
                j += 1
            flush()
            segs.append(("literal", text[i:j]))
            i = j
            continue

        if c == "'":
            j = i + 1
            while j < n:
                d = text[j]
                if d == "\\":
                    j += 2
                    continue
                if d == "'":
                    j += 1
                    break
                if d == "\n":
                    break
                j += 1
            flush()
            segs.append(("literal", text[i:j]))
            i = j
            continue

        if c == "/" and i + 1 < n and text[i + 1] == "/":
            j = i + 2
            while j < n:
                if text[j] == "\\" and text[j + 1:j + 2] == "\n":
                    j += 2
                    continue
                if text[j] == "\\" and text[j + 1:j + 3] == "\r\n":
                    j += 3
                    continue
                if text[j] == "\n":
                    break
                j += 1
            if keep_comments:
                flush()
                segs.append(("literal", text[i:j]))
            i = j
            continue
        if c == "/" and i + 1 < n and text[i + 1] == "*":
            end = text.find("*/", i + 2)
            end = n if end == -1 else end + 2
            if keep_comments:
                flush()
                segs.append(("literal", text[i:end]))
            else:
                buf.append(" ")
            i = end
            continue

        buf.append(c)
        i += 1

    flush()
    return segs


def _collapse_code(s):
    s = s.replace("\r\n", "\n").replace("\r", "\n")
    s = re.sub(r"[ \t]+\n", "\n", s)
    s = re.sub(r"\n{2,}", "\n", s)
    return s


def clean_text(text, strip_comments=True, collapse=True):
    if not strip_comments and not collapse:
        return text
    segs = _scan_segments(text, keep_comments=not strip_comments)
    if not collapse:
        return "".join(t for _, t in segs)
    out = "".join(_collapse_code(t) if kind == "code" else t for kind, t in segs)
    out = out.lstrip("\n")
    return (out.rstrip("\n") + "\n") if out else out


DEFINE_RE = re.compile(r'^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)', re.M)


def _logical_end(text, line_start):
    i, n = line_start, len(text)
    while True:
        nl = text.find("\n", i)
        if nl == -1:
            return n
        line = text[i:nl]
        if line.endswith("\r"):
            line = line[:-1]
        if line.endswith("\\"):
            i = nl + 1
            continue
        return nl + 1


def find_defines(text):
    return [(m.start(), _logical_end(text, m.start()), m.group(1))
            for m in DEFINE_RE.finditer(text)]


def _used_outside(text, name, span):
    lo, hi = span
    for m in re.finditer(r"\b" + re.escape(name) + r"\b", text):
        if m.start() >= hi or m.end() <= lo:
            return True
    return False


def remove_unused_defines(text):
    removed = []
    while True:
        drop = [d for d in find_defines(text)
                if not _used_outside(text, d[2], (d[0], d[1]))]
        if not drop:
            break
        for start, end, name in sorted(drop, key=lambda d: d[0], reverse=True):
            text = text[:start] + text[end:]
            removed.append(name)
    return text, removed


def transform(text, do_comments=True, do_defines=True, do_collapse=True):
    if do_comments or do_collapse:
        text = clean_text(text, strip_comments=do_comments, collapse=do_collapse)
    removed = []
    if do_defines:
        text, removed = remove_unused_defines(text)
    return text, removed


def process_source_file(path, dry_run, do_comments, do_defines, do_collapse):
    with open(path, encoding="utf-8", errors="replace") as f:
        original = f.read()
    new, removed = transform(original, do_comments, do_defines, do_collapse)
    changed = new != original
    if changed and not dry_run:
        with open(path, "w", encoding="utf-8") as f:
            f.write(new)
    return changed, removed


def process_json_file(path, dry_run, do_comments, do_defines, do_collapse):
    with open(path, encoding="utf-8") as f:
        data = json.load(f)
    lang = (data.get("language") or "").strip().lower()
    code = data.get("code")
    if not code or lang not in ("c", "cpp"):
        return False, []
    new, removed = transform(code, do_comments, do_defines, do_collapse)
    changed = new != code
    if changed and not dry_run:
        data["code"] = new
        with open(path, "w", encoding="utf-8") as f:
            json.dump(data, f, ensure_ascii=False, indent=2)
    return changed, removed


def resolve_root(task, args):
    candidates = []
    if args.output:
        candidates.append(os.path.normpath(args.output))
    candidates.append(os.path.normpath(os.path.join(args.base_dir, task)))
    candidates.append(os.path.normpath(task))
    for c in candidates:
        if os.path.exists(c + ".zip"):
            return c
    tried = ", ".join(c + ".zip" for c in candidates)
    print(f"error: {task}: no problem archive found (tried: {tried})",
          file=sys.stderr)
    return None


def discover_tasks(base_dir):
    if not os.path.isdir(base_dir):
        sys.exit(f"error: no such directory: {base_dir}")
    return sorted(os.path.splitext(fn)[0] for fn in os.listdir(base_dir)
                  if fn.lower().endswith(".zip"))


def process_problem(root, args, do_comments, do_defines, do_collapse):
    zip_path = root + ".zip"
    parent = os.path.dirname(root) or "."
    name = os.path.basename(root)

    if os.path.isdir(root):
        shutil.rmtree(root)
    print(f"[unzip] {zip_path} -> {root}/", file=sys.stderr)
    shutil.unpack_archive(zip_path, parent, "zip")

    solutions_dir = os.path.join(root, "solutions")
    submissions_dir = os.path.join(root, "submissions")
    tot_files = tot_defines = 0

    if os.path.isdir(solutions_dir):
        files = defines = 0
        for fn in sorted(os.listdir(solutions_dir)):
            if os.path.splitext(fn)[1].lower() not in C_EXTS:
                continue
            changed, removed = process_source_file(
                os.path.join(solutions_dir, fn), args.dry_run,
                do_comments, do_defines, do_collapse)
            files += changed
            defines += len(removed)
        print(f"[solutions] {files} file(s) cleaned, "
              f"{defines} unused #define(s) removed", file=sys.stderr)
        tot_files += files
        tot_defines += defines

    if not args.no_json and os.path.isdir(submissions_dir):
        files = defines = 0
        for fn in sorted(os.listdir(submissions_dir)):
            if not fn.endswith(".json"):
                continue
            changed, removed = process_json_file(
                os.path.join(submissions_dir, fn), args.dry_run,
                do_comments, do_defines, do_collapse)
            files += changed
            defines += len(removed)
        print(f"[submissions] {files} JSON file(s) cleaned, "
              f"{defines} unused #define(s) removed", file=sys.stderr)
        tot_files += files
        tot_defines += defines

    if args.keep_unzipped:
        print(f"[done] extracted folder left at {root}/ (zip unchanged)", file=sys.stderr)
    elif args.dry_run:
        shutil.rmtree(root)
        print("[dry-run] nothing written; archive left unchanged", file=sys.stderr)
    else:
        archive = shutil.make_archive(root, "zip", root_dir=parent, base_dir=name)
        shutil.rmtree(root)
        print(f"[zip] {archive} (folder removed)", file=sys.stderr)

    return tot_files, tot_defines


def main():
    ap = argparse.ArgumentParser(
        description="Strip comments, drop unused #define macros and collapse blank "
                    "lines in a dumped infoarena problem's C/C++ sources.")
    ap.add_argument("task", nargs="*",
                    help="problem slug(s), e.g. lgput; omit to process every "
                         "<base-dir>/*.zip")
    ap.add_argument("--base-dir", default="infoarena",
                    help="parent directory holding <task>.zip (default: infoarena)")
    ap.add_argument("-o", "--output",
                    help="problem root path (its <root>.zip is processed); "
                         "overrides --base-dir/<task>, single problem only")
    ap.add_argument("--list", action="store_true",
                    help="just print the problems that would be processed, then exit")
    ap.add_argument("--no-json", action="store_true",
                    help="do not rewrite the embedded code in submissions/*.json")
    ap.add_argument("--keep-comments", action="store_true",
                    help="do not strip // and /* */ comments")
    ap.add_argument("--keep-defines", action="store_true",
                    help="do not remove unused #define macros")
    ap.add_argument("--keep-blank-lines", action="store_true",
                    help="do not collapse runs of blank lines")
    ap.add_argument("--dry-run", action="store_true",
                    help="report what would change but write nothing "
                         "(the archive is left unchanged)")
    ap.add_argument("--keep-unzipped", action="store_true",
                    help="leave the extracted folder in place instead of "
                         "re-zipping it (the original zip is kept)")
    args = ap.parse_args()

    do_comments = not args.keep_comments
    do_defines = not args.keep_defines
    do_collapse = not args.keep_blank_lines
    if not (do_comments or do_defines or do_collapse):
        sys.exit("error: nothing to do (all transforms disabled)")

    tasks = args.task or discover_tasks(args.base_dir)
    if args.output and len(tasks) != 1:
        sys.exit("error: --output names one problem root; pass exactly one slug")
    if not tasks:
        sys.exit(f"error: no problem archives found in {args.base_dir}/")

    if args.list:
        for t in tasks:
            print(t)
        print(f"\n{len(tasks)} problem(s).", file=sys.stderr)
        return 0

    single = len(tasks) == 1
    if not single:
        print(f"=== cleaning {len(tasks)} problems ===", file=sys.stderr)

    ok, failed = [], []
    tot_files = tot_defines = 0
    for i, task in enumerate(tasks, 1):
        if not single:
            print(f"\n----- [{i}/{len(tasks)}] {task} -----", file=sys.stderr)
        root = resolve_root(task, args)
        if root is None:
            failed.append(task)
            continue
        try:
            files, defines = process_problem(
                root, args, do_comments, do_defines, do_collapse)
        except Exception as exc:
            print(f"    ! {task}: {type(exc).__name__}: {exc}", file=sys.stderr)
            failed.append(task)
            continue
        ok.append(task)
        tot_files += files
        tot_defines += defines

    if not single:
        print(f"\n=== done: {len(ok)} ok, {len(failed)} failed; "
              f"{tot_files} file(s) cleaned, {tot_defines} unused #define(s) removed ===",
              file=sys.stderr)
        if failed:
            print(f"    failed: {failed}", file=sys.stderr)
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
