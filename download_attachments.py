#!/usr/bin/env python3

import argparse
import html
import os
import re
import sys
import time
import urllib.parse
import urllib.request
import zipfile

BASE = "https://www.infoarena.ro/problema"
UA = "Mozilla/5.0 (compatible; infoarena-scraper/1.0)"

FILE_RE = re.compile(r'action=download&amp;file=([^&"]+)&amp;safe_only')


def get(url):
    req = urllib.request.Request(url, headers={"User-Agent": UA})
    with urllib.request.urlopen(req, timeout=60) as r:
        return r.read()


def list_attachments(task):
    url = f"{BASE}/{task}?action=attach-list&display_entries=250"
    page = get(url).decode("utf-8", "replace")
    names = {html.unescape(m) for m in FILE_RE.findall(page)}
    return sorted(names)


def download(task, name, dest_dir, delay, force=False):
    out_path = os.path.join(dest_dir, name)
    if os.path.exists(out_path) and os.path.getsize(out_path) > 0 and not force:
        print(f"  = {name} (already downloaded)", file=sys.stderr)
        return out_path
    q = urllib.parse.quote(name)
    url = f"{BASE}/{task}?action=download&file={q}&safe_only=false"
    data = get(url)
    with open(out_path, "wb") as f:
        f.write(data)
    print(f"  + {name} ({len(data)} bytes)", file=sys.stderr)
    time.sleep(delay)
    return out_path


def unzip(path, dest_dir):
    target = os.path.join(dest_dir, os.path.splitext(os.path.basename(path))[0])
    os.makedirs(target, exist_ok=True)
    with zipfile.ZipFile(path) as z:
        z.extractall(target)
        n = len(z.namelist())
    print(f"    unzipped {os.path.basename(path)} -> {target}/ ({n} files)", file=sys.stderr)


def main():
    ap = argparse.ArgumentParser(description="Download & unzip infoarena problem attachments.")
    ap.add_argument("task", help="problem slug, e.g. cmlsc")
    ap.add_argument("-o", "--output", help="output directory (default: <task>_attachments)")
    ap.add_argument("--no-unzip", action="store_true", help="do not extract .zip files")
    ap.add_argument("--delay", type=float, default=0.2, help="seconds between downloads (default 0.2)")
    args = ap.parse_args()

    dest = args.output or f"{args.task}_attachments"
    os.makedirs(dest, exist_ok=True)

    print(f"Listing attachments for '{args.task}' ...", file=sys.stderr)
    names = list_attachments(args.task)
    if not names:
        print("No attachments found (problem may have none, or the page layout changed).",
              file=sys.stderr)
        return
    print(f"Found {len(names)} files. Downloading into {dest}/", file=sys.stderr)

    zips = []
    for name in names:
        try:
            path = download(args.task, name, dest, args.delay)
        except Exception as e:
            print(f"  ! {name}: {e}", file=sys.stderr)
            continue
        if path.lower().endswith(".zip"):
            zips.append(path)

    if zips and not args.no_unzip:
        print(f"Unzipping {len(zips)} archive(s) ...", file=sys.stderr)
        for z in zips:
            try:
                unzip(z, dest)
            except Exception as e:
                print(f"  ! unzip {z}: {e}", file=sys.stderr)

    print(f"Done. Files in {dest}/", file=sys.stderr)


if __name__ == "__main__":
    main()
