#!/usr/bin/env python3
"""
Batch-dump every problem from the infoarena "Arhiva educationala".

This just calls infoarena_dump.py once per problem in the PROBLEMS list below,
so each problem lands in infoarena/<slug>/ (CSV, solutions/, details/, tests/,
solution.txt). Problems are processed independently: if one fails, the rest
still run, and a summary is printed at the end.

The list is a plain Python vector so you can curate it by hand: delete or
comment out (with a leading '#') any problem you don't want. Interactive
problems such as 'cbinteractiv' have no ordinary submissions/tests, so it is
commented out by default.

Usage:
    python3 dump_archive.py                     # dump every listed problem
    python3 dump_archive.py --zip               # dump each problem and compress it
    python3 dump_archive.py --cookie "SSID=..." # forward flags to infoarena_dump.py
    python3 dump_archive.py --no-attachments --max-pages 2
    python3 dump_archive.py --only cmlsc fmcm   # dump just these (still must be listed)

With --zip, each problem is compressed to infoarena/<slug>.zip and its folder
removed. A re-run then skips any problem whose .zip already exists (infoarena_dump.py
does this), so an interrupted batch resumes cheaply without re-downloading finished
problems. Pass --force to re-dump them anyway.

Any option that is not --only/--list is passed straight through to every
infoarena_dump.py call (e.g. --cookie, --no-attachments, --no-code, --langs).

Source list: https://www.infoarena.ro/arhiva-educationala  (63 problems)
"""

import argparse
import os
import subprocess
import sys

# --- the problems to dump ---------------------------------------------------
# One slug per entry; the comment is the problem title, for reference.
# Comment out or delete any line to exclude that problem from the dataset.
PROBLEMS = [
    "euclid2",        # Algoritmul lui Euclid
    "cmlsc",          # Cel mai lung subsir comun
    "euclid3",        # Algoritmul lui Euclid extins
    "royfloyd",       # Floyd-Warshall/Roy-Floyd
    "sortaret",       # Sortare topologica
    "strmatch",       # Potrivirea sirurilor
    "evaluare",       # Evaluarea unei expresii
    "arbint",         # Arbori de intervale
    "scmax",          # Subsir crescator maximal
    "dijkstra",       # Algoritmul lui Dijkstra
    "ciur",           # Ciurul lui Eratosthenes
    "permutari",      # Generare de permutari
    "lgput",          # Ridicare la putere in timp logaritmic
    "bfs",            # BFS - Parcurgere in latime
    "dfs",            # Parcurgere DFS - componente conexe
    "aib",            # Arbori indexati binar
    "rmq",            # Range minimum query
    "combinari",      # Combinari
    "cautbin",        # Cautare binara
    "radixsort",      # Radix Sort
    "cuplaj",         # Cuplaj maxim in graf bipartit
    "inversmodular",  # Invers modular
    "disjoint",       # Paduri de multimi disjuncte
    "trie",           # Trie
    "deque",          # Deque
    "heapuri",        # Heapuri
    "apm",            # Arbore partial de cost minim
    "ctc",            # Componente tare conexe
    "algsort",        # Sortare prin comparare
    "infasuratoare",  # Infasuratoare convexa
    "hashuri",        # Hashuri
    "biconex",        # Componente biconexe
    "maxflow",        # Flux maxim
    "fmcm",           # Flux maxim de cost minim
    "ciclueuler",     # Ciclu Eulerian
    "ssm",            # Subsecventa de suma maxima
    "podm",           # Parantezare optima de matrici
    "hamilton",       # Ciclu hamiltonian de cost minim
    "cmcm",           # Cuplaj maxim de cost minim
    "huffman",        # Coduri Huffman
    "lca",            # Lowest Common Ancestor
    "2sat",           # 2SAT
    "sdo",            # Statistici de ordine
    "pinex",          # Principiul includerii si excluderii
    "kfib",           # Al k-lea termen Fibonacci
    "submultimi",     # Submultimi
    "cmap",           # Cele mai apropiate puncte din plan
    "bellmanford",    # Algoritmul Bellman-Ford
    "ssnd",           # Suma si numarul divizorilor
    "stirling",       # Numerele lui Stirling
    "nim",            # Jocul NIM
    "rucsac",         # Problema rucsacului
    "gauss",          # Algoritmul lui Gauss
    "heavypath",      # Heavy Path Decomposition
    "damesah",        # Problema Damelor
    "ahocorasick",    # Aho-Corasick
    "aria",           # Aria
    "elmaj",          # Elementul majoritar
    "darb",           # Diametrul unui arbore
    "mergeheap",      # Heapuri cu reuniune
    # "cbinteractiv", # Cbinteractiv  (interactive problem - excluded from dataset)
    "abce",           # Arbori binari de cautare echilibrati
    "interclas",      # Interclasare
]
# ---------------------------------------------------------------------------

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
