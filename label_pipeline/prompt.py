MAX_CODE_CHARS = 24000

SYSTEM_HEAD = """\
You classify competitive-programming submissions from infoarena.ro by the algorithm they implement.

Reply with a single JSON object and nothing else, with the keys in this order:
{"algorithm": <string>, "evidence": <string>, "unoptimized": <bool>, "confidence": <number between 0 and 1>}

"algorithm"
  The canonical name of the algorithm the submission is *intended* to implement, in its
  standard eponymous form: "Edmonds-Karp", "Dinic", "Ford-Fulkerson", "Push-Relabel",
  "Kruskal", "Dijkstra", "Aho-Corasick", "Knuth-Morris-Pratt", "Euclid extins".
  Name the algorithm and nothing else. No complexity, no data structure, no problem name,
  no qualifiers such as "optimized"/"efficient"/"with heap", no trailing punctuation.
  Where an algorithm has no eponymous name, use the short standard description of the
  method ("programare dinamica", "cautare binara", "backtracking", "brute force").
  Classify intent, not correctness: a buggy submission, or one that scores 0, still gets
  the algorithm it was trying to be.

"evidence"
  At most 15 words, and you must write it before deciding "unoptimized".
  Name the concrete repeated work you found, and where: which loop re-runs which step,
  and what result is thrown away between iterations. For example
  "bfs() called inside the while that pushes one path, level[] discarded each time".
  If the code follows the standard form of the algorithm, write exactly "standard form".

"unoptimized"
  true when the code implements a recognisably weaker *variant of the same algorithm*
  instead of its standard form; false otherwise.

  Decide it from the structure you just named in "evidence", never from the score, the
  formatting, or a general sense that the code is clumsy.

  The boundary is different for every algorithm, so read it off the list below for the
  one you named, and compare the code against those two forms. Doing one search per
  augmenting path is the *definition* of Ford-Fulkerson and the *defect* of
  Edmonds-Karp: the same structure means opposite answers under different names. Never
  carry one algorithm's weak pattern over to another.

  Constant factors never make this true on their own: I/O method, adjacency matrix vs
  adjacency list, recursion vs explicit stack, global vs local arrays, an unordered scan
  inside a loop that is already dominated by something bigger, or clumsy style.

  Both answers need the same standard of proof. Write "standard form" only when you
  have checked the weak pattern named for this algorithm and the code does not match
  it - not as a default when the code is hard to follow.

"confidence"
  Your confidence in "algorithm", from 0 to 1. Use below 0.5 when the code is truncated,
  unreadable, or does not implement a recognisable algorithm at all.
"""

MAX_SOLUTION_CHARS = 5000

SOLUTION_BLOCK = """\

The official editorial for this problem, in Romanian. Where it contrasts a
straightforward approach with an optimization needed for full marks, that contrast is
usually exactly what "unoptimized" tracks here, and it outranks the textbook definition
of the algorithm. It describes approaches, not this submission: never take a score it
quotes as this submission's score.
{solution}
"""

VOCAB_BLOCK = """\

Names already used for this problem. Reuse one of these verbatim whenever it fits the
submission; only invent a new name when none of them describes the code:
{vocab}
"""

VARIANTS_BLOCK = """\

What "unoptimized" means for each of those names on this problem. Match the code
against the pair belonging to the name you chose, and nothing else:
{variants}
"""

EXAMPLES_BLOCK = """\

Submissions from this problem already labelled by a human. They fix what the
"unoptimized" flag means *here*: compare a new submission against the structural
difference these show, not against their surface style or their length.
{examples}
"""

EXAMPLE_CODE_CHARS = 2200


def problem_block(meta, name):
    title = meta.get("title") or name
    lines = ["", "Problem: %s (%s)" % (title, name)]
    statement = (meta.get("statement") or "").strip()
    if statement:
        if len(statement) > 1200:
            statement = statement[:1200].rsplit(" ", 1)[0] + " [...]"
        lines.append("Statement: %s" % statement)
    for key, caption in (("input_format", "Input"), ("output_format", "Output")):
        text = " ".join((meta.get(key) or "").split())
        if text:
            lines.append("%s: %s" % (caption, text[:300]))
    constraints = (meta.get("constraints") or "").strip()
    if constraints:
        constraints = " ".join(constraints.split())
        lines.append("Constraints: %s" % constraints[:400])
    for key, caption in (("time_limit", "Time limit"), ("memory_limit", "Memory limit")):
        if meta.get(key):
            lines.append("%s: %s" % (caption, meta[key]))
    return "\n".join(lines) + "\n"


def build_system(name, meta, vocabulary=(), examples=(), variants=None,
                 solution=None):
    parts = [SYSTEM_HEAD, problem_block(meta, name)]
    if solution:
        parts.append(SOLUTION_BLOCK.format(
            solution=clip(solution, MAX_SOLUTION_CHARS)))
    if vocabulary:
        parts.append(VOCAB_BLOCK.format(
            vocab="\n".join("  - %s" % v for v in vocabulary)))
    rendered = []
    for algorithm in vocabulary:
        spec = (variants or {}).get(algorithm)
        if not spec:
            continue
        rendered.append(
            "  %s\n      unoptimized=false: %s\n      unoptimized=true : %s"
            % (algorithm, spec.get("standard", "").strip(),
               spec.get("weak", "").strip()))
    if rendered:
        parts.append(VARIANTS_BLOCK.format(variants="\n".join(rendered)))
    if examples:
        rendered = []
        for index, (algorithm, unoptimized, code) in enumerate(examples, 1):
            rendered.append(
                '\nExample %d:\n```\n%s\n```\n-> {"algorithm": "%s", "unoptimized": %s}'
                % (index, clip(code, EXAMPLE_CODE_CHARS), algorithm,
                   "true" if unoptimized else "false"))
        parts.append(EXAMPLES_BLOCK.format(examples="\n".join(rendered)))
    return "".join(parts)


def clip(code, limit=MAX_CODE_CHARS):
    if len(code) <= limit:
        return code
    head = limit * 2 // 3
    tail = limit - head
    return "%s\n\n/* [...%d characters elided...] */\n\n%s" % (
        code[:head], len(code) - limit, code[-tail:])


def build_user(row, code):
    header = "language: %s | score: %s/100" % (
        row.get("language") or "unknown", row.get("score") or "?")
    return ("%s\nThe score is context only - decide \"unoptimized\" from the code.\n\n"
            "```\n%s\n```" % (header, clip(code)))


CONSOLIDATE_SYSTEM = """\
You are consolidating the algorithm names produced by an automatic classifier for a
single competitive-programming problem into one clean vocabulary.

You receive a list of raw names with their occurrence counts. Return JSON only:
{"canonical": [<name>, ...], "aliases": {<raw name>: <canonical name>, ...}}

Rules:
  - Merge names that denote the same algorithm into one canonical spelling, preferring
    the standard eponymous form and the most frequent spelling ("edmonds karp",
    "Edmonds Karp algorithm", "EdmondsKarp" -> "Edmonds-Karp").
  - Keep genuinely different algorithms apart. Do not merge Dinic into Edmonds-Karp.
  - Strip qualifiers such as "optimized", "efficient", "naive", "slow", "with heap":
    they are carried separately and must not appear in a canonical name.
  - Every raw name must appear as a key in "aliases", including ones whose canonical
    form is itself.
  - Order "canonical" by descending total count.
"""


VARIANT_SYSTEM = """\
You are writing down where a human labeller has actually drawn the line between the
standard implementation of one algorithm and the weaker variant of it, on one
competitive-programming problem.

You are given the algorithm name and real submissions to that problem, each marked
with the label the human gave it. Return JSON only:
{"standard": <string>, "weak": <string>}

Rules:
  - At most 25 words each. Describe control flow a reader can check in the source:
    which loop repeats which search, what gets recomputed, what is thrown away.
  - Derive the line from the submissions you were given and nothing else. Where the
    human's line disagrees with the textbook definition of the algorithm, follow the
    human: their convention is what the labels have to match.
  - Never mention complexity classes, scores, file size, or code style.
  - You are describing two implementations of the *same* algorithm. Do not describe a
    different algorithm as the standard form.
"""


VARIANT_USER = """\
Algorithm: {algorithm}
{blocks}
State the difference the human is drawing between these.
"""
