# infoarena submissions dataset

> **Note:** This README was completely AI-generated. It may contain mistakes, so
> check the code when in doubt.

Scripts for scraping submissions from [infoarena.ro](https://www.infoarena.ro),
judging them locally, cleaning the sources, and labelling each submission with
the algorithm it implements.

A typical run: `dump_archive.py` (which calls `infoarena_dump.py`) fills
`infoarena/`, `count_submissions.py` shows progress, `repair_details.py` and
`evaluate_local.py` fix and re-check the per-test reports,
`remove_unused_defines.py` / `split_solutions.py` / `split_csv_by_language.py`
clean and split the sources, and `label_pipeline/` adds the algorithm labels.

## Contents

- Collecting data: `scrape_infoarena.py`, `download_attachments.py`, `infoarena_dump.py`, `dump_archive.py`
- Inspecting the dataset: `count_submissions.py`, `rank_problems.py`
- Fixing and judging: `repair_details.py`, `evaluate_local.py`
- Cleaning and splitting: `remove_unused_defines.py`, `split_solutions.py`, `split_csv_by_language.py`
- Labelling pipeline: `label_pipeline/`

## Collecting data

### `scrape_infoarena.py`

Scrapes the submissions list ("monitor") of an infoarena problem, and optionally
each submission's source, per-test report and the problem's own pages.
`infoarena_dump.py` uses it as a library, and it also works on its own.

```bash
python3 scrape_infoarena.py cmlsc                  # all pages -> cmlsc.csv
python3 scrape_infoarena.py cmlsc --max-pages 3    # first 3 pages only
python3 scrape_infoarena.py cmlsc -o out.csv       # custom output file
python3 scrape_infoarena.py cmlsc --code           # also fetch sources -> cmlsc_sources/
python3 scrape_infoarena.py cmlsc --details        # per-test reports -> cmlsc_details/
python3 scrape_infoarena.py cmlsc --json           # per-submission JSON (implies --code --details)
python3 scrape_infoarena.py cmlsc --solution --statement --problem-json
python3 scrape_infoarena.py cmlsc --code --langs all --cookie "..."
```

#### Flags

| flag | effect |
| --- | --- |
| `-o`, `--output` | CSV path (default `<task>.csv`) |
| `--max-pages N` | stop after N monitor pages |
| `--code`, `--code-dir` | download sources (default dir `<task>_sources`) |
| `--keep-missing` | with `--code`, keep rows whose source can't be fetched |
| `--details`, `--details-dir` | parse each job page into a per-test CSV |
| `--json`, `--submissions-dir` | one `<username>_<id>.json` per submission, built from files already downloaded |
| `--solution` | save the "Indicatii de rezolvare" hints to `solution.txt` (or `solution_MISSING.txt`) |
| `--statement` | save the statement to `statement.txt` (or `statement_MISSING.txt`) |
| `--problem-json` | save statement, I/O format, limits and samples to `<task>.json` |
| `--langs` | languages whose sources are saved (default `c,cpp,java`, `all` for everything) |
| `--cookie` | session cookie for login-gated sources (or `INFOARENA_COOKIE`) |

#### Notes

- Viewing a source on infoarena needs a logged-in account, usually one that has
  solved the problem. Copy the `Cookie` request header from your browser's
  DevTools and pass it with `--cookie`.
- There's a small delay between requests. Don't hammer the server.
- Files that already exist are skipped. `infoarena_dump.py --refetch` sets
  `REFETCH` here to re-read specific kinds anyway.
- A test counts as passed (`ok=YES`) when it earned points or its message
  contains the whole word "corect" (or is just "ok"). Older dumps used a plain substring check
  that also matched "Incorect", which `repair_details.py` fixes.

### `download_attachments.py`

Downloads every attachment of an infoarena problem (test data, graders, ...) and
unzips any `.zip` files it finds.

```bash
python3 download_attachments.py cmlsc                # -> cmlsc_attachments/
python3 download_attachments.py cmlsc -o mydir       # custom directory
python3 download_attachments.py cmlsc --no-unzip     # keep zips as they are
python3 download_attachments.py cmlsc --delay 0.2    # pause between downloads
```

The list comes from `https://www.infoarena.ro/problema/<task>?action=attach-list`
and each file is fetched with `?action=download&file=<name>&safe_only=false`.
Each archive is extracted into a folder named after it.

Files already on disk (and non-empty) are skipped, so an interrupted run can
just be started again. Test data is often big, so don't re-fetch it more than
you need to.

`infoarena_dump.py` imports `list_attachments`, `download` and `unzip` from
this file.

### `infoarena_dump.py`

Dumps everything about one infoarena problem into a single directory. It
combines `scrape_infoarena.py` (submissions, sources, reports) and
`download_attachments.py` (test data), and both must sit in the same folder.

```bash
python3 infoarena_dump.py cmlsc
python3 infoarena_dump.py cmlsc --max-pages 2          # fewer submissions (debug)
python3 infoarena_dump.py cmlsc --refetch details      # re-read per-test reports
python3 infoarena_dump.py cmlsc --refetch code,json --max-pages 2
python3 infoarena_dump.py cmlsc --refetch all
python3 infoarena_dump.py cmlsc --no-code              # skip sources
python3 infoarena_dump.py cmlsc --no-details           # skip per-test reports
python3 infoarena_dump.py cmlsc --no-solution          # skip solution.txt
python3 infoarena_dump.py cmlsc --no-attachments       # skip test data
python3 infoarena_dump.py cmlsc --zip                  # -> cmlsc.zip, folder removed
python3 infoarena_dump.py cmlsc --code-delay 0.05 --attach-delay 0.2
python3 infoarena_dump.py cmlsc --cookie "..."         # or set INFOARENA_COOKIE
```

#### Output layout

```
infoarena/<problem>/
    <problem>.csv     every submission (one row each)
    <problem>.json    problem metadata: statement, I/O format, limits, samples
    statement.txt     the statement as plain text
    solution.txt      "Indicatii de rezolvare" hints, or solution_MISSING.txt with the link
    solutions/        one source file per submission (<id>.<ext>)
    details/          one per-test report CSV per submission (<id>.csv)
    submissions/      one JSON per submission (<username>_<id>.json): code, score,
                      compiler, submit time, per-test report
    tests/            downloaded attachments
```

The JSON files are the main format now. The CSV, `solutions/` and `details/` are
kept next to them. Both JSON kinds are built from files already on disk.

#### Re-running

Files that already exist are skipped, which makes re-runs cheap but also means a
wrong file stays wrong. If `<problem>.zip` exists, it is unpacked and the dump
resumes into it.

- `--refetch KIND[,KIND...]` re-reads the given kinds (`code`, `details`, `json`,
  `problem-json`, `solution`, `statement`, `attachments`, or `all`). Nothing is
  deleted up front and only what the run reaches is refreshed, so
  `--refetch details --max-pages 2` updates the newest two pages and leaves the
  rest alone. CSV rows the run didn't reach are carried over from the old CSV.
- `--force` deletes the existing zip and dumps from scratch.

By default only `c`, `cpp` and `java` sources are saved (`--langs all` saves
everything), and submissions whose source can't be fetched are dropped from the
CSV unless `--keep-missing` is given.

### `dump_archive.py`

Runs `infoarena_dump.py` once for every problem in the infoarena
"Arhiva educationala" (https://www.infoarena.ro/arhiva-educationala). Each
problem ends up in `infoarena/<slug>/`. If one problem fails, the rest still
run, and a summary is printed at the end.

```bash
python3 dump_archive.py                        # every problem in PROBLEMS
python3 dump_archive.py --list                 # just print what would run
python3 dump_archive.py --only cmlsc fmcm      # a subset (must be in PROBLEMS)
python3 dump_archive.py --zip                  # compress each problem when done
python3 dump_archive.py --cookie "SSID=..."    # forwarded to infoarena_dump.py
python3 dump_archive.py --no-attachments --max-pages 2
python3 dump_archive.py --refetch details      # re-read every problem's reports
python3 dump_archive.py --refetch code --only cmlsc --max-pages 2
```

The `PROBLEMS` list at the top of the file is plain Python, so edit it by hand
to pick problems. `cbinteractiv` is interactive and has no normal submissions or
tests, so it is not in the list.

Any option other than `--only` and `--list` is passed straight to every
`infoarena_dump.py` call (`--cookie`, `--refetch`, `--no-attachments`,
`--no-code`, `--langs`, ...).

With `--zip`, each problem becomes `infoarena/<slug>.zip` and its folder is
removed. A later run skips problems whose zip already exists, so a stopped batch
resumes cheaply.

To re-read something, prefer `--refetch KIND[,KIND...]` (`code`, `details`,
`json`, `problem-json`, `solution`, `statement`, `attachments`, `all`) over
`--force`. `--refetch` only overwrites what the run actually reaches, so it
works with `--only` and `--max-pages`. `--force` throws each problem's dump
away and starts over.

## Inspecting the dataset

### `count_submissions.py`

Shows how much data has been collected under `infoarena/`, one row per problem.

```bash
python3 count_submissions.py                    # scans ./infoarena
python3 count_submissions.py path/to/infoarena
python3 count_submissions.py --csv              # machine-readable output
```

#### Columns

| column | meaning |
| --- | --- |
| submissions | data rows in `<problem>.csv` (the authoritative count) |
| solutions | source files in `solutions/` |
| details | per-test report CSVs in `details/` |
| json | per-submission JSON files in `submissions/` (`<username>_<id>.json`) |
| pjson | `yes` if `<problem>.json` exists |
| tests | `yes` if `tests/` has any files |
| hints | `yes` for `solution.txt`, `MISSING` for `solution_MISSING.txt` |
| complete | submissions with a details file, counted only when both tests and hints exist |

A problem can be a plain directory (`infoarena/<problem>/`) or an archive made by
`infoarena_dump.py --zip` (`infoarena/<problem>.zip`). Archives are read in
place and never unpacked to disk. If both forms exist, the directory wins.

### `rank_problems.py`

Ranks infoarena problems by their total number of submissions, read live from
the website (not from the local dataset).

```bash
python3 rank_problems.py                    # top 50 + summary table
python3 rank_problems.py --top 0            # every problem
python3 rank_problems.py --archive edu      # educational archive only
python3 rank_problems.py --archive main     # main archive only
python3 rank_problems.py --csv > rank.csv   # CSV, always every row
python3 rank_problems.py --workers 4        # go easier on the server
python3 rank_problems.py --cookie "..."     # or set INFOARENA_COOKIE
```

Every problem is tagged with the archive it comes from:

- `educational`: the "Arhiva educationala", i.e. the `PROBLEMS` list in
  `dump_archive.py`, which is what the local dataset contains.
- `main`: the general "Arhiva de probleme" (`/arhiva`). These problems don't
  overlap with the educational ones and aren't in the local dataset.

For each problem, one monitor request reads the "(N rezultate)" total. The main
archive has ~2400 problems, so requests run on a small thread pool
(`--workers`, default 8). A summary table at the end breaks the totals down per
archive.

## Fixing and judging

### `repair_details.py`

Fixes the per-test reports already stored in the infoarena archive. Changes are
made in place in each `<problem>.zip`, and the copies of the same reports inside
`submissions/*.json` are fixed to match.

```bash
python3 repair_details.py --dry-run      # report, change nothing
python3 repair_details.py                # repair every problem
python3 repair_details.py lgput 2sat     # just these
python3 repair_details.py --no-json      # leave submissions/*.json alone
```

Both fixes are idempotent: a second run finds nothing to do.

#### Fix 1: `ok`

`scrape_infoarena.py` used to decide whether a test passed with
`"corect" in message`, which "Incorect" also matches. Every wrong answer with an
"incorect"-family message was stored as `ok=YES`: 455,924 rows, 17.9% of the
archive. The scraper now uses `\bcorect\b`, but it skips files that already
exist, so re-running it doesn't fix old data. This script does, offline.

It does **not** recompute `ok` from the message. On problems with a
floating-point checker a passing test reads "OK, eroare maxima 0.000000000",
which no message rule recognises, and recomputing would wrongly fail 2,500+
rows. Only rows with the bug's exact signature are touched: "corect" present,
but not as a whole word. All eleven such messages in the archive are failures,
so the change is always YES -> NO, never the reverse.

#### Fix 2: `test_points`

`details/` used to store only the group's score. infoarena shows two numbers,
Punctaj/test and Punctaj/grupa, which differ when a group is partly solved. The
scraper now records both, and this fills the column in where the value can be
known: when each test is its own group, the group score is the test score. When
tests share a group the per-test score isn't in the data, so the column is left
empty instead of guessed. That's 35 problems filled and 27 left empty (those
need a re-scrape).

### `evaluate_local.py`

Judges archived infoarena submissions on this machine and stores the verdicts in
`details_local/`, next to the archive's own `details/`.

Each submission is compiled, run once per test under the problem's time and
memory limits, and checked either against the test's `.ok` file or, for the 18
problems that ship one, with the problem's own `tests/grader_eval.cpp`. The
result goes back into `<problem>.zip` as `<problem>/details_local/<id>.csv`,
with the same columns as `details/<id>.csv`:

```
submission_id,test,subtask,time,memory,message,ok,test_points,subtask_points
```

Messages use infoarena's wording ("OK", "Incorect", "Time limit exceeded",
"Memory limit exceeded", "Killed by Signal N", "Non zero exit status: N",
"Fisier de iesire lipsa"). A compile error gives a header-only CSV, which is how
the archive records it too.

Only `c`, `cpp` and `java` are judged. Other languages are skipped and
reported, never written out as zero.

#### Usage

```bash
python3 evaluate_local.py lgput --submission 3037277
python3 evaluate_local.py lgput                     # every submission
python3 evaluate_local.py lgput --limit 50 -j 8     # first 50, 8 at a time
python3 evaluate_local.py                           # every problem (long!)
python3 evaluate_local.py lgput --force             # re-judge ones already done
python3 evaluate_local.py lgput --reset             # empty details_local/, redo all
python3 evaluate_local.py lgput --dry-run -v        # judge and print, write nothing
python3 evaluate_local.py lgput --code mysol.cpp    # judge your own file
python3 evaluate_local.py lgput --verify            # compare with archived scores
```

Other flags: `--time-factor`, `--grace`, `--java-grace`, `--as-cap`,
`--mem-baseline`, `--stop-early`, `--flush-every`, `--base-dir`. See `--help`.

#### Scoring

infoarena groups tests into subtasks, and a subtask only scores if every test in
it passes. That grouping isn't in `tests/`, so it is taken from the archive's
`details/*.csv` (which subtask each test is in, and what the subtask is worth).
This gives exactly 100 points on all 62 problems. If it ever fails, each test
becomes its own subtask.

`test_points` is what a test earned by itself and `subtask_points` is what its
group got. They differ when a group is only partly solved, so a submission's
total is summed per subtask, not per test. A test's own value comes from the
largest `test_points` seen for it in `details/`, or from its subtask when the
subtask holds a single test, or from what `grader_eval.cpp` awards. When none of
those apply (old `details/` without `test_points` and grouped tests) the column
is left empty, the same way `repair_details.py` leaves it.

`ok` is `YES` exactly when the test earned its own points. It is not the group
score, so a correct test in a failed group is still `ok=YES` with
`subtask_points` 0. The archive's `details/` doesn't always match this because
of an old scraper bug (`"corect" in message` also matched "Incorect"), see the `repair_details.py` section.

#### Time limit

Local timing can't match infoarena's. This machine is 2x to 15x faster than the
original judge, and infoarena's own records aren't consistent (305ms "OK" next to
175ms "Time limit exceeded" on the same 175ms problem). Marking a correct
solution as TLE is worse than letting a slow one pass, so `--time-factor`
defaults to 3 and applies to both the verdict and the kill deadline. Use
`--time-factor 1` to hold submissions to the stated limit. The measured time is
always recorded, so borderline cases are visible.

#### Killing runaway programs

Each program is started by a small C supervisor (compiled on the fly) that polls
it every 0.2ms and kills its whole process group once it goes over
`limit * time-factor + --grace` wall time or over the memory limit. In testing,
infinite loops, sleeping loops, forking programs and endless printers all died
within 180ms, and memory hogs within 30ms of the limit. `RLIMIT_CPU` and
`RLIMIT_FSIZE` are set as backstops. A program stuck in an uninterruptible write
can take a few hundred ms longer to die.

#### Memory

Memory is resident size, read from `/proc`, not address space. Submissions in
this archive declare 800MB global arrays or reserve 4GB vectors they never touch.
That costs nothing and passes on infoarena, but would fail any `RLIMIT_AS` cap,
so `--as-cap` is off by default. `getrusage` isn't used either, because
`ru_maxrss` is inherited across fork and would report the Python interpreter's
~10MB. The supervisor forks from ~200KB instead.

The ~1.5MB a static C++ binary uses before `main()` is measured once and
subtracted, so the number is the submission's own use. `--mem-baseline 0` turns
that off.

#### Accuracy

Re-judging 200 submissions across 8 problems reproduced infoarena's score for
136 of the 150 that have one. The other 14 all scored higher locally, never
lower, so nothing correct is being failed.

## Cleaning and splitting

### `remove_unused_defines.py`

Cleans up the C/C++ sources of dumped infoarena problems. For each problem it
unzips `<problem>.zip`, rewrites every C/C++ source (the files in `solutions/`
and the `code` field of `submissions/*.json`), then zips it back. With no slug it
does every `<base-dir>/*.zip`.

```bash
python3 remove_unused_defines.py                            # every problem in infoarena/
python3 remove_unused_defines.py --list                     # show which ones that is
python3 remove_unused_defines.py lgput                      # just one
python3 remove_unused_defines.py lgput dijkstra ciur        # a few
python3 remove_unused_defines.py lgput --dry-run            # report, write nothing
python3 remove_unused_defines.py lgput --no-json            # skip submissions/*.json
python3 remove_unused_defines.py lgput --keep-comments      # don't strip comments
python3 remove_unused_defines.py lgput --keep-defines       # don't drop unused #define
python3 remove_unused_defines.py lgput --keep-blank-lines   # don't collapse blank lines
python3 remove_unused_defines.py lgput --keep-unzipped      # leave the folder, don't re-zip
```

#### What it does

1. Strips `//` and `/* */` comments.
2. Removes every `#define` (object- or function-like) whose name is never used
   anywhere else in the file.
3. Collapses runs of blank lines and trailing spaces.

#### Why it's safe without compiling

- Comments and blank lines don't change what a program does. The only exception
  would be code that uses `__LINE__` or `#line`, which contest solutions don't.
- A `#define` is removed only if its name appears nowhere else: not in code,
  other macros, `#ifdef` or `defined()`, and (since comments go first) not in
  comments either. A macro nobody references can't affect anything.
- String, char and raw-string literals are detected and left alone, so a `//`,
  `/*` or blank line inside a literal is never touched.

It errs on the side of keeping things: it may leave something removable, but it
never removes something that's used.

### `split_solutions.py`

Sorts each problem's `solutions/` into per-language folders and keeps only the
submissions listed in `<problem>.csv`.

```bash
python3 split_solutions.py --dry-run               # show what would happen
python3 split_solutions.py                         # split ./infoarena in place
python3 split_solutions.py path/to/infoarena
python3 split_solutions.py --only dijkstra 2sat    # just these
python3 split_solutions.py --langs cpp,java        # skip C
python3 split_solutions.py --drop-solutions        # also delete solutions/
python3 split_solutions.py --no-zip                # leave directories uncompressed
python3 split_solutions.py -o solutions_split      # copy elsewhere, touch nothing
```

#### Output

```
infoarena/<problem>/cpp_sol/<id>.cpp    (.cc / .cxx / .c++ too)
infoarena/<problem>/c_sol/<id>.c
infoarena/<problem>/java_sol/<id>.java
```

Files are byte-for-byte copies of the originals.

#### What gets kept

A source is kept only if:

- it's C++, C or Java;
- its id is a row in `<problem>.csv` (the CSV is usually much shorter than
  `solutions/`; dijkstra lists 2000 of its 39851 saved sources);
- that row's score isn't 0 (a blank score counts as 0);
- it doesn't use `__attribute__` or `__restrict__`/`__restrict` (GCC-only);
- it doesn't use `final` as a whole word. `final` is a keyword in C++
  (`class X final`) and Java, so it can't just be renamed, and rewriting it
  inside a string would change the program's output. Dropping the file is the
  only safe option. Names like `final_answer` or `is_final` are fine.

#### Zipping

The original `solutions/` is kept unless `--drop-solutions` is given. That
option loses data, since most saved sources aren't in the CSV, so try
`--dry-run` first. Keeping it means those files are stored twice, which makes
each archive bigger.

Every problem ends up zipped. An existing archive is rebuilt next to the old one
and swapped in only when it's complete, so an interrupted run changes nothing. A
problem stored as a directory is compressed to `<problem>.zip` and the folder
removed, the same shape `infoarena_dump.py --zip` produces. `--no-zip` leaves it
as a directory. If a `<problem>.zip` already exists next to the directory, it is
not overwritten: the directory is left alone and a warning is printed.

If both a directory and a zip exist for a problem, the directory is read (same
rule as `count_submissions.py`).

With `--out DIR`, no problem is touched. The kept sources go to
`DIR/<problem>.zip` (or `DIR/<problem>/` with `--no-zip`).

### `split_csv_by_language.py`

Splits each problem's `<problem>.csv` into one CSV per language, stored next to
the per-language source folders that `split_solutions.py` creates.

```bash
python3 split_csv_by_language.py --dry-run           # show what would happen
python3 split_csv_by_language.py                     # split ./infoarena in place
python3 split_csv_by_language.py path/to/infoarena
python3 split_csv_by_language.py --only maxflow dijkstra
python3 split_csv_by_language.py --langs cpp,c       # only these two
python3 split_csv_by_language.py --in-zip            # rewrite archives too (slow)
python3 split_csv_by_language.py -o csv_by_lang      # write elsewhere, touch nothing
python3 split_csv_by_language.py --csv maxflow.csv   # a single loose CSV
python3 split_csv_by_language.py --keep-unknown      # keep rows with no source
```

#### Output

```
<problem>/cpp_sol/<problem>.csv    .cpp / .cc / .cxx / .c++
<problem>/c_sol/<problem>.csv      .c
<problem>/java_sol/<problem>.csv   .java
<problem>/pas_sol/<problem>.csv    .pas
<problem>/py_sol/<problem>.csv     .py
<problem>/rs_sol/<problem>.csv     .rs
```

Rows are copied unchanged, with the same header and order. Languages with no rows
get no file. The original `<problem>.csv` stays where it is and re-running
overwrites the same files, so nothing is ever appended twice.

#### How the language is found

The CSV's `language` column has always been empty so far, so the language comes
from the saved source file: `solutions/<id>.<ext>`, or `<lang>_sol/<id>.<ext>`
if `solutions/` has already been dropped. Rows with no saved source are counted
as `nolang` and dropped, unless `--keep-unknown` writes them to
`unknown_sol/<problem>.csv`.

#### Directories vs. archives

Problems can be directories or `.zip` archives. If both exist, the directory
wins (same rule as `split_solutions.py`, whose readers this file reuses).
Directories are split in place. Archives are only read unless `--in-zip` is
given, because adding files means recompressing the whole thing (`dijkstra.zip`
is 91 MB with 121k members). `-o` writes the result elsewhere and doesn't touch
any problem.

`--csv FILE` splits one CSV kept outside the collection, such as a labelled copy
of a problem's rows. The languages still come from the problem with the same
name in the collection directory.

## Labelling pipeline (`label_pipeline/`)

Fills the `label` column of every `infoarena/<problem>/<problem>.csv` with the
algorithm each submission implements, using DeepSeek.

A label is exactly the algorithm name, with ` neoptimizat` appended when the
submission implements the weak variant of that algorithm:

```
Edmonds-Karp                 flow pushed along every augmenting path of one BFS
Edmonds-Karp neoptimizat     BFS rerun from scratch for each path pushed
Dinic
Dinic neoptimizat
Push-Relabel
```

Nothing else goes in the column: no complexity, no data structure, no
`optimizat` (a bare name already means the standard variant). The classifier
judges *intent*, so a buggy 0-point submission still gets the algorithm it was
trying to be.

### Running

```bash
export DEEPSEEK_API_KEY=sk-...

# one problem, checked against the hand labels already in maxflow.csv
python3 label_pipeline/pipeline.py maxflow
python3 label_pipeline/pipeline.py maxflow --eval
python3 label_pipeline/pipeline.py maxflow --report

# everything (62 problems, ~120k submissions)
python3 label_pipeline/pipeline.py --workers 16
```

Useful flags: `--limit N` (cap per problem), `--sidecar` (never touch the
original csv), `--mock` (offline keyword classifier, no API calls, for
exercising the plumbing), `--force` (re-label), `--rediscover` (rebuild the
vocabulary), `--base-url` (point at a self-hosted OpenAI-compatible endpoint),
`--estimate` (token and cost projection).

### Choosing a model

`--model` picks it, `--base-url` picks the endpoint. The default is
`deepseek-chat`.

```bash
python3 label_pipeline/pipeline.py maxflow                            # deepseek-chat (V3)
python3 label_pipeline/pipeline.py maxflow --model deepseek-reasoner  # R1
python3 label_pipeline/pipeline.py maxflow \
    --base-url http://localhost:8000/v1 --model deepseek-ai/DeepSeek-V3
```

Any OpenAI-compatible endpoint works — vLLM, sglang, ollama, or another
provider hosting DeepSeek. With `--base-url` set, `DEEPSEEK_API_KEY` becomes
optional, since self-hosted servers usually want no credential.

A model whose name contains `reasoner`, `r1`, `think`, `v4` or `flash` is
detected as a thinking model, and its completion budget goes from 200 to 16384
tokens, because hidden thinking tokens are charged against it. The narrower set
that also *rejects* `response_format` and `temperature` — `reasoner`, `r1` — has
those two parameters dropped as well. Override the budget with `--max-tokens`.

`--thinking off` tells a v4 model to answer without thinking at all, sent as
`extra_body={"thinking": {"type": "disabled"}}`. On `deepseek-v4-flash` that
takes a submission from ~8000 completion tokens to ~25, which is a ~15x cut in
the cost of a run and removes the truncation failure entirely. `--thinking on`
forces thinking; `auto` (the default) sends nothing and leaves the model's own
default in place. An endpoint that rejects the parameter gets it dropped after
the first 400, with a warning, rather than failing the run. Note that
`enable_thinking: false` is *not* the spelling DeepSeek accepts — it is ignored
silently and the model thinks anyway.

If an unrecognised model still runs out of budget, the reply comes back empty or
half-written; the client notices, quadruples the budget up to 32768 and retries,
then keeps the raised value for the rest of the run so only the first call pays
for the discovery. Passing `--max-tokens` explicitly pins the budget and turns
that escalation off.

**Which to use.** `deepseek-chat` is the right default: this is a
recognise-the-pattern task, not a reasoning task, and the vocabulary pinned into
the system message already does the work that reasoning would. It is also two
orders of magnitude cheaper — a thinking model spends ~5000 hidden tokens per
submission to write a 30-token answer, so maxflow alone costs ~$0.44 on
`deepseek-chat` against ~$13.67 on `deepseek-v4-flash`. `deepseek-reasoner`
is worth trying only on the `unoptimized` flag if `--eval` shows it landing badly
on maxflow — distinguishing "one BFS per augmenting path" from "one BFS per
phase" is the one genuinely subtle judgement in the task. It costs several times
more per submission because of the thinking tokens.

A cheap way to compare: run both into different `--out` directories with
`--limit 200`, then `--eval` each against the maxflow hand labels.

```bash
python3 label_pipeline/pipeline.py maxflow --out /tmp/v3 --limit 200 --sidecar
python3 label_pipeline/pipeline.py maxflow --out /tmp/r1 --limit 200 --sidecar \
    --model deepseek-reasoner
python3 label_pipeline/pipeline.py maxflow --out /tmp/v3 --eval
python3 label_pipeline/pipeline.py maxflow --out /tmp/r1 --eval
```

The per-problem cache is keyed by directory, not by model, so use a separate
`--out` per model or the second run will just reuse the first one's answers.

### How it works

Per problem, two passes:

1. **Discovery.** A score-stratified sample (`--sample`, default 60) is
   classified with no vocabulary, then the model folds the raw names into one
   canonical list. Seeded with any labels a human already wrote in the csv, and
   cached to `labels/<problem>.vocab.json`.
2. **Bulk.** Every csv row is classified with that vocabulary pinned into the
   system message.

The second pass is what keeps the column consistent. Classifying 2000
submissions independently yields `Edmonds-Karp`, `edmonds karp` and
`Edmonds Karp algorithm` as three different labels; pinning the vocabulary, then
resolving each answer through an alias table and a fuzzy match, yields one.

The model answers in JSON mode with `{algorithm, evidence, unoptimized,
confidence}`. `evidence` comes before `unoptimized` on purpose: the model has to
name the concrete repeated work it found, in at most 15 words, before it is
allowed to judge. It is stored on every record, so `--report` and `--eval` can
show *why* a row was called weak. The ` neoptimizat` suffix is composed in code
from the boolean rather than parsed out of prose, so the label format cannot
drift. An answer below `--min-confidence` may reuse an existing name but may not
mint a new one.

Two things pin the flag down, both cached in the system prefix:

- `--examples N` (default 6) puts hand-labelled submissions of *this* problem in
  the prompt, chosen as contrasting pairs of the same algorithm — Edmonds-Karp
  weak against Edmonds-Karp standard, Dinic against Dinic — so the model learns
  the structural difference rather than "Edmonds-Karp means weak". `--eval`
  holds these rows out.
- The **official editorial**, `<problem>/solution.txt`, pinned verbatim (52 of the
  62 problems have one; the rest carry a `solution_MISSING.txt` placeholder).
  This is the cheapest and most general of the three, because it needs no hand
  labels: infoarena editorials routinely say "this approach gets ~70 points,
  this optimization gets 100", and that sentence *is* the boundary the flag
  tracks. maxflow's says the straightforward Edmonds-Karp scores ~70 and that
  100 needs augmenting along every sink-adjacent leaf of one BFS tree "fara a
  mai reface BFS-ul" - which is precisely how the labeller used `neoptimizat`.
  Disable with `--no-editorial`.
- A **variant spec** per algorithm, written to `<problem>.vocab.json`, saying what
  the standard and weak forms look like here. It is derived by showing the model
  the human's own labelled code, never from the algorithm's name, because the
  textbook disagrees with this dataset: one BFS per augmenting path *is*
  Edmonds-Karp to a textbook, and `neoptimizat` to the labeller. Asked from the
  name alone, the model answers "none - this shape is the algorithm" for every
  entry and drags the flag down with it. Algorithms with no weak submission on
  record get "answer false", which is what stops Ford-Fulkerson — where one DFS
  per path is the definition — from being called weak.

### Cost and throughput

Everything constant for a problem (rules, statement, vocabulary) lives in the
system message and only the source code varies, so DeepSeek's context cache
serves the bulk of each prompt at cache-hit price. Identical sources — about one
submission in twelve — are classified once and the answer fanned out to the
twins.

`--estimate` over all 62 problems on `deepseek-chat`: 120,037 submissions, ~40M
code tokens plus ~84M cached prefix tokens, **~$21 at list price, ~$10
off-peak**. On `deepseek-v4-flash --thinking off` it is ~$26 / ~$13; leave
thinking on and it is roughly forty times that, because 5000 hidden tokens per
submission dwarf everything else.

Those figures come from the `PRICES` table at the top of `pipeline.py`, keyed by
model and holding peak list prices; `--estimate` and the end-of-run report both
look the running model up in it, and fall back to the `deepseek-chat` tariff for
an unknown name. Edit the table if a tariff has moved or add a row for a model
that is not in it, or the cost report will quietly be about a different model.

### Output

```
labels/<problem>.jsonl        one record per submission: id, code hash, algorithm,
                              unoptimized, confidence, label, model, timestamp
labels/<problem>.vocab.json   canonical names + alias table
labels/<problem>.csv          only for problems that are still zipped
```

The jsonl is append-only and flushed per record, so an interrupted run resumes
without re-paying for what it already did. Labels are written back into
`<problem>/<problem>.csv` in place for unpacked problems (atomically, via a temp
file); zipped problems get a sidecar csv in `labels/` instead, since rewriting a
246 MB archive to change one column is not worth it.

Labels a human already wrote are never overwritten unless `--force` is passed.

### Files

| file | role |
| --- | --- |
| `pipeline.py` | CLI, both passes, write-back, `--eval`, `--report`, `--estimate` |
| `sources.py` | reads a problem from an unpacked dir or straight out of its zip |
| `prompt.py` | system/user message construction, consolidation prompt |
| `client.py` | DeepSeek JSON-mode client with backoff; offline mock |
| `normalize.py` | name cleaning, alias/fuzzy resolution, label composition |
| `store.py` | append-only JSONL cache, resume, code-hash dedup |

Records carry `evidence` as well as the label, so a run can be audited after the
fact without re-calling the model.

Write-back preserves the csv's own header rather than a fixed field list, so a
column added to a `<problem>.csv` by hand round-trips untouched instead of being
dropped on the next run.

### Caveats

- Zipped problems are **never extracted**. Members are read straight out of the
  archive with `zipfile`, so running against all 62 problems adds nothing to disk
  beyond `labels/`. Only rows that actually need work get decompressed, so a
  resumed run costs no reads at all.
- The zips hold the full scrape (~40k submissions each) but the csv is the
  trimmed ~2000-row subset, so the csv is what drives the pipeline.
- Two maxflow rows have no scraped source and stay unlabelled.
- `--report` lists singleton labels and low-confidence rows; those are where
  mistakes concentrate and are worth a skim before trusting a problem's column.
- **The `unoptimized` flag is still the weak part**, though much less so than it
  was. On the 34 scoreable maxflow hand labels, `deepseek-v4-flash --thinking
  off`:

  | prompt | algorithm | flag |
  | --- | --- | --- |
  | no few-shots, no variant spec, no editorial | 33/34 (97.1%) | 9/34 (26.5%) |
  | + hand-labelled few-shots | 33/34 (97.1%) | 19/34 (55.9%) |
  | + label-derived variant spec | 31/34 (91.2%) | 25/34 (73.5%) |
  | + `solution.txt` editorial | 31/34 (91.2%) | 27/34 (79.4%) |
  | + statement input/output format | 32/34 (94.1%) | 27/34 (79.4%) |

  Four hand labels turned out to be **wrong**, all in one cluster: 3351110,
  3354175, 3354191 and 3354192 augment every sink-adjacent leaf of one BFS tree
  before rebuilding it, which is exactly the optimization the editorial says is
  worth 100 points, yet they were labelled `neoptimizat`. 3351110 was also one of
  the six few-shots, so the prompt was teaching the boundary backwards. They have
  since been corrected in the csv, which lifts the flag to 30/34 (88.2%) and the
  combined score to 29/34 (85.3%) - a measurement correction, not a model gain:
  on the rows common to both runs the flag is 28/32 either way.

  Every remaining error is now Dinic: three submissions whose sink-side BFS makes
  them read as weak Edmonds-Karp, and two without a current-arc pointer where
  whether that counts as `neoptimizat` is a convention call, not a bug.

  The variant spec buys 6 rows of flag accuracy and costs 2 rows of algorithm
  accuracy: it describes control flow, and some of that description reads like
  evidence for a name. An attempt to fence that off ("nothing below tells you
  *which* algorithm this is") made the flag worse and the algorithm no better,
  so it is not in the prompt. At n=34 a 2-row difference is inside the noise;
  treat the flag as "usable, spot-check it", not as measured to a point.
- The maxflow hand labels also use `optimizat` and `modificat`, a third state the
  boolean cannot express. `--eval` skips those rows and says how many, and
  `pick_examples` never teaches from them; `normalize.clean` still strips the
  qualifier when a label is read back for any other purpose.
- **Only maxflow has hand labels**, so only maxflow gets few-shots and a variant
  spec. The other 61 problems get the editorial and the generic rule in
  `SYSTEM_HEAD`, which is somewhere between the 26.5% and 79.4% rows above and
  has not been measured - there is no gold to measure it against. Hand-label a
  dozen submissions of a problem before trusting its ` neoptimizat` column, and
  use `--no-variants --examples 0` on maxflow if you want to measure what that
  configuration is really worth.

### Modules

#### `pipeline.py`

The command-line entry point of the labelling pipeline. It fills the `label`
column of each `<problem>.csv` with the algorithm every submission implements,
plus ` neoptimizat` when the submission is the weak variant. The overview above covers model choice, cost and accuracy.

```bash
export DEEPSEEK_API_KEY=sk-...
python3 label_pipeline/pipeline.py maxflow              # label one problem
python3 label_pipeline/pipeline.py maxflow --eval       # compare with hand labels
python3 label_pipeline/pipeline.py maxflow --report     # singletons, low confidence
python3 label_pipeline/pipeline.py --estimate           # token and cost projection
python3 label_pipeline/pipeline.py --workers 16         # every problem
python3 label_pipeline/pipeline.py maxflow --mock       # offline, no API calls
```

##### Two passes per problem

1. **Discovery.** A score-stratified sample (`--sample`, default 60) is
   classified with no vocabulary, then the model merges the raw names into one
   canonical list. Any labels a human already wrote in the CSV are used as seeds.
   The result is cached in `labels/<problem>.vocab.json`.
2. **Bulk.** Every CSV row is classified with that vocabulary pinned into the
   system message, so answers stay consistent instead of drifting between
   "Edmonds-Karp", "edmonds karp" and "Edmonds Karp algorithm".

The ` neoptimizat` suffix is added in code from the model's `unoptimized` flag,
not parsed from its text.

##### Main flags

| flag | effect |
| --- | --- |
| `--root`, `--out` | where problems are read from and where `labels/` goes |
| `--model`, `--base-url` | model name and OpenAI-compatible endpoint |
| `--max-tokens`, `--thinking`, `--reasoning-effort`, `--temperature` | request settings (see `client.py`) |
| `--workers` | parallel requests (default 8) |
| `--min-confidence` | below this an answer can reuse a name but not create a new one (default 0.4) |
| `--examples N` | hand-labelled few-shot examples of this problem (default 6) |
| `--no-variants`, `--no-editorial` | leave the variant spec or `solution.txt` out of the prompt |
| `--limit N` | at most N rows per problem |
| `--force`, `--rediscover` | re-label everything, rebuild the vocabulary |
| `--sidecar` | never write into the original CSV |
| `--eval`, `--report`, `--estimate` | evaluation, review and cost modes |

##### Output

```
labels/<problem>.jsonl        one record per submission (see store.py)
labels/<problem>.vocab.json   canonical names, aliases, variant specs
labels/<problem>.csv          written only for problems that are still zipped
```

Unpacked problems get their CSV rewritten in place, atomically, keeping its own
header. Human labels are only overwritten with `--force`.

`PRICES` at the top of the file holds the per-model prices used by `--estimate`
and the end-of-run report. Unknown models fall back to `deepseek-chat`'s price.

#### `client.py`

The model client used by `pipeline.py`: DeepSeek (or any OpenAI-compatible
endpoint) in JSON mode, with retries, plus an offline mock.

##### `build_client(args)`

Returns a `MockClient` with `--mock`, otherwise a `DeepSeekClient` configured
from the command-line arguments.

##### `DeepSeekClient`

- Uses the `openai` package with base URL `https://api.deepseek.com` unless
  `--base-url` is set. Needs `DEEPSEEK_API_KEY`, except with a custom base URL,
  where a placeholder key is used.
- `complete_json(system, user)` sends one chat request and returns the parsed
  JSON object from the reply.
- Retries 429 and 5xx errors with exponential backoff and jitter (up to 6 tries).
- Models whose name contains `reasoner`, `r1`, `think`, `v4` or `flash` count as
  thinking models and start with a 16384-token budget instead of 200.
  `reasoner`/`r1` models also get `response_format` and `temperature` dropped,
  since they reject them.
- If a reply comes back empty or cut off, the budget is multiplied by 4 (up to
  32768) and kept for the rest of the run. Passing `--max-tokens` fixes the
  budget and turns this off.
- `--thinking on|off` is sent as `extra_body={"thinking": {"type": ...}}`, and
  `--reasoning-effort` as `reasoning_effort`. If the endpoint rejects either one
  with a 400/422, it is dropped with a warning and the call is retried.
- Token usage (prompt, cache hits, completion) is tallied in `Usage` so the
  pipeline can report cost at the end.

##### `MockClient`

Guesses the algorithm with a few regexes over the code (Dinic, Edmonds-Karp,
Dijkstra, Kruskal, ...) and flags `unoptimized` when BFS is called inside a
`while` loop. It's only for testing the pipeline without an API key.

#### `prompt.py`

Builds the messages sent to the model.

Everything that stays the same for a problem goes in the system message, and
the submission's code is the only user message. That way the prefix is identical
across the ~2000 calls for a problem and DeepSeek's context cache serves it
cheaply.

##### Pieces

- `SYSTEM_HEAD`: the classification rules and the reply format
  `{"algorithm", "evidence", "unoptimized", "confidence"}`. `evidence` comes
  before `unoptimized` so the model has to name the repeated work it found
  before judging.
- `problem_block(meta, name)`: title, a trimmed statement, I/O format,
  constraints and limits from `<problem>.json`.
- `build_system(...)`: joins the head, the problem block, the editorial
  (`solution.txt`, clipped to 5000 chars), the pinned vocabulary, the per-algorithm
  variant specs and the few-shot examples.
- `build_user(row, code)`: the language, the score (as context only) and the code.
- `clip(code)`: keeps the first two thirds and the last third of anything over
  24000 characters, with a marker in between.
- `CONSOLIDATE_SYSTEM`: merges raw algorithm names into a canonical list
  (discovery pass).
- `VARIANT_SYSTEM` / `VARIANT_USER`: asks the model to describe what the standard
  and weak versions of each algorithm look like in this problem, based on
  hand-labelled code.

#### `sources.py`

Reads a problem's data whether it's an unpacked directory (`infoarena/<name>/`)
or an archive (`infoarena/<name>.zip`). Archives are read in place, never
extracted.

Both layouts contain:

```
<name>/<name>.csv            submission table (~2000 rows, what gets labelled)
<name>/<name>.json           problem metadata (title, statement, limits)
<name>/solution.txt          the official editorial, when there is one
<name>/submissions/*.json    one file per submission, source in "code"
```

The zips hold the full scrape (tens of thousands of submissions) while the CSV
is a 2000-row subset, so the CSV decides what gets labelled and `submissions/`
is only used to look up code for those ids.

##### API

- `ProblemSource(root, name)`: raises `FileNotFoundError` if neither the
  directory nor the zip exists.
  - `meta()`: the problem JSON as a dict.
  - `solution()`: the editorial text, or `None`.
  - `rows()`: the CSV rows. Labels from hand-labelled CSVs named `<name>*.csv`
    in the root folder or its parent (e.g. `maxflow.csv`, `maxflow_my_label.csv`)
    are merged in by id. `hand_labels` says which files were used.
  - `code(submission_id)`: the source of one submission, or `None`.
  - `close()`: closes the zip if one is open.
- `discover(root)`: sorted names of every problem under `root`.

#### `normalize.py`

Turns a model's free-form algorithm name into one stable label per problem.
The final label is the algorithm name, plus ` neoptimizat` for the weak variant.

##### Functions

- `clean(name)`: strips quotes, punctuation and qualifiers such as
  "optimized", "naive", "algorithm", "varianta" (English and Romanian), and
  normalizes dashes and spaces.
- `key(name)`: lowercase, no diacritics, letters and digits only. Used for
  matching.
- `compose(algorithm, unoptimized)`: builds the label, e.g.
  `Edmonds-Karp neoptimizat`.
- `split(label)`: the reverse, returning `(algorithm, unoptimized)`.

##### `Vocabulary`

The canonical names for one problem, plus an alias table and variant specs.

- `resolve(name)` checks, in order, the alias table, an exact key match, and a
  fuzzy match (`difflib`, cutoff 0.87). Fuzzy hits are remembered as aliases. If
  nothing matches, the name is added as new (unless `learn=False`).
- `to_dict()` / `from_dict()` save and load it as `<problem>.vocab.json`.

#### `store.py`

An append-only cache of results, one JSONL file per problem
(`labels/<problem>.jsonl`).

Every labelled submission is written and flushed right away, so an interrupted
run resumes without paying for work it already did.

##### API

- `code_hash(code)`: SHA-1 of the source with comments and whitespace removed.
  Duplicate submissions (~8% of a problem) share a hash and are answered from the
  cache for free.
- `ResultStore(path)`: loads existing records (bad lines are skipped).
  - `get(id)` / `get_by_hash(digest)`: look up a record. Failed records
    (`error` set) are never used for hash lookups.
  - `put(record)`: index and append one record. Thread-safe.
  - `labels()`: `{id: label}` for every successful record.
