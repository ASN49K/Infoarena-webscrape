#!/usr/bin/env python3

import argparse
import os
import subprocess
import sys

PROBLEMS = [
    "euclid2",
    "cmlsc",
    "euclid3",
    "royfloyd",
    "sortaret",
    "strmatch",
    "evaluare",
    "arbint",
    "scmax",
    "dijkstra",
    "ciur",
    "permutari",
    "lgput",
    "bfs",
    "dfs",
    "aib",
    "rmq",
    "combinari",
    "cautbin",
    "radixsort",
    "cuplaj",
    "inversmodular",
    "disjoint",
    "trie",
    "deque",
    "heapuri",
    "apm",
    "ctc",
    "algsort",
    "infasuratoare",
    "hashuri",
    "biconex",
    "maxflow",
    "fmcm",
    "ciclueuler",
    "ssm",
    "podm",
    "hamilton",
    "cmcm",
    "huffman",
    "lca",
    "2sat",
    "sdo",
    "pinex",
    "kfib",
    "submultimi",
    "cmap",
    "bellmanford",
    "ssnd",
    "stirling",
    "nim",
    "rucsac",
    "gauss",
    "heavypath",
    "damesah",
    "ahocorasick",
    "aria",
    "elmaj",
    "darb",
    "mergeheap",
    "abce",
    "interclas",
]

DUMP_SCRIPT = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                           "infoarena_dump.py")


def main():
    ap = argparse.ArgumentParser(
        description="Batch-run infoarena_dump.py over the educational archive.",
        epilog="Unrecognised options are forwarded to every infoarena_dump.py call.")
    ap.add_argument("--only", nargs="+", metavar="SLUG",
                    help="dump only these problems (must appear in PROBLEMS)")
    ap.add_argument("--list", action="store_true",
                    help="just print the problems that would be dumped, then exit")
    args, passthrough = ap.parse_known_args()

    problems = list(PROBLEMS)
    if args.only:
        wanted = set(args.only)
        unknown = wanted - set(PROBLEMS)
        if unknown:
            print(f"warning: not in PROBLEMS, skipping: {sorted(unknown)}",
                  file=sys.stderr)
        problems = [p for p in PROBLEMS if p in wanted]

    if args.list:
        for p in problems:
            print(p)
        print(f"\n{len(problems)} problem(s).", file=sys.stderr)
        return 0

    if not problems:
        print("Nothing to dump (PROBLEMS is empty or --only matched nothing).",
              file=sys.stderr)
        return 1

    print(f"=== batch dump: {len(problems)} problems ===", file=sys.stderr)
    if passthrough:
        print(f"    forwarding to infoarena_dump.py: {' '.join(passthrough)}",
              file=sys.stderr)

    ok, failed = [], []
    for i, slug in enumerate(problems, 1):
        print(f"\n----- [{i}/{len(problems)}] {slug} -----", file=sys.stderr)
        cmd = [sys.executable, DUMP_SCRIPT, slug, *passthrough]
        rc = subprocess.run(cmd).returncode
        (ok if rc == 0 else failed).append(slug)
        if rc != 0:
            print(f"    ! {slug}: infoarena_dump.py exited {rc}", file=sys.stderr)

    print(f"\n=== done: {len(ok)} ok, {len(failed)} failed ===", file=sys.stderr)
    if failed:
        print(f"    failed: {failed}", file=sys.stderr)
    return 0 if not failed else 1


if __name__ == "__main__":
    sys.exit(main())
