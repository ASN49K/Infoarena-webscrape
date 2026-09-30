#!/usr/bin/env python3

import argparse
import concurrent.futures
import csv
import io
import json
import math
import os
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import time
import zipfile

DETAILS_HEADER = ["submission_id", "test", "subtask", "time", "memory",
                  "message", "ok", "test_points", "subtask_points"]

LANGS = ("cpp", "c", "java")

CXX_STDS = ("c++17", "c++11", "gnu++98")

FSIZE_CAP = 64 * 1024 * 1024

COMPILE_TIMEOUT = 60
EVAL_TIME_LIMIT = 30

OUTER_GRACE = 5.0

RUNNER_C = r"""
/* usage: runner REPORT WALL_MS CPU_SEC AS_BYTES FSIZE RSS_KB OUT PROG [ARG...]
 *
 * Runs PROG under the given limits and writes
 * "killed over_memory cpu_us maxrss_kb wall_ms status" to REPORT. A zero limit
 * means "leave that one alone".
 *
 * PROG is killed as soon as either deadline passes: WALL_MS of wall-clock time,
 * or RSS_KB of resident memory (sampled from /proc, since the resident size is
 * what infoarena limits and what an address-space rlimit cannot express). Cutting
 * a memory hog off at the limit rather than letting it run to the time deadline
 * also keeps peak usage bounded when several of these run in parallel.
 * Before finishing it wipes PROG's process group, so anything PROG spawned dies
 * with it.
 */
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

static void cap(int what, long long value) {
    struct rlimit rl;
    if (value <= 0) return;
    rl.rlim_cur = (rlim_t)value;
    rl.rlim_max = (rlim_t)value;
    setrlimit(what, &rl);
}

static long long ms_since(struct timespec *t0) {
    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return (now.tv_sec - t0->tv_sec) * 1000LL
         + (now.tv_nsec - t0->tv_nsec) / 1000000LL;
}

/* Resident size in KB, straight from /proc/PID/statm (field 2, in pages). */
static long long rss_kb(pid_t pid) {
    char path[64];
    long long size = 0, resident = 0;
    FILE *f;
    snprintf(path, sizeof path, "/proc/%ld/statm", (long)pid);
    if ((f = fopen(path, "r")) == NULL) return 0;
    if (fscanf(f, "%lld %lld", &size, &resident) != 2) resident = 0;
    fclose(f);
    return resident * (sysconf(_SC_PAGESIZE) / 1024);
}

int main(int argc, char **argv) {
    if (argc < 9) return 127;
    const char *report = argv[1];
    long long wall_ms = atoll(argv[2]), cpu_sec = atoll(argv[3]);
    long long as_bytes = atoll(argv[4]), fsize = atoll(argv[5]);
    long long rss_limit = atoll(argv[6]);
    const char *out_path = argv[7];
    char **prog = &argv[8];
    struct timespec t0;
    struct rusage ru;
    int status = 0, killed = 0, over_memory = 0, tick = 0;
    long long peak = 0;
    pid_t pid;
    FILE *f;

    setsid();                       /* our caller can wipe this whole session */
    clock_gettime(CLOCK_MONOTONIC, &t0);

    pid = fork();
    if (pid < 0) return 127;
    if (pid == 0) {
        int fd;
        setpgid(0, 0);              /* own group, so we can sweep it and live */
        fd = open("/dev/null", O_RDONLY);
        if (fd >= 0) dup2(fd, 0);
        fd = open(out_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd >= 0) { dup2(fd, 1); dup2(fd, 2); }
        /* No core dumps. Not for the disk they cost: core_pattern here pipes to
         * apport, and while the kernel writes a crashed program down that pipe
         * the process is neither running nor reapable -- half a second on this
         * machine, which is longer than most problems' deadline, so every
         * segfault came back as "Time limit exceeded" with ~5ms of CPU on the
         * clock. The limit is 1 byte and not 0 on purpose: core(5) is explicit
         * that a RLIMIT_CORE of 0 does not suppress a piped dump, while any
         * nonzero limit too small to hold one does. */
        { struct rlimit z; z.rlim_cur = z.rlim_max = 1; setrlimit(RLIMIT_CORE, &z); }
        cap(RLIMIT_CPU, cpu_sec);   /* whole seconds only: a coarse backstop */
        cap(RLIMIT_FSIZE, fsize);   /* a loop that prints forever stops here */
        cap(RLIMIT_AS, as_bytes);
        execv(prog[0], prog);
        _exit(127);
    }
    setpgid(pid, pid);              /* also set here: whichever wins, no race */

    /* Leave the pid behind so a supervisor that has to kill us can still find
     * the process we were watching. */
    if ((f = fopen(report, "w")) != NULL) {
        fprintf(f, "PID %ld\n", (long)pid);
        fclose(f);
    }

    memset(&ru, 0, sizeof ru);
    for (;;) {
        pid_t r = wait4(pid, &status, WNOHANG, &ru);
        if (r == pid) break;
        if (r < 0 && errno != EINTR) break;

        if (ms_since(&t0) >= wall_ms) killed = 1;
        /* Sampling /proc costs more than the wait check, so do it every ~2ms;
         * nothing can allocate past the limit and get back under it in between,
         * because we only ever compare against the peak seen so far. */
        if (rss_limit > 0 && ++tick % 10 == 0) {
            long long now_kb = rss_kb(pid);
            if (now_kb > peak) peak = now_kb;
            if (peak > rss_limit) over_memory = 1;
        }
        if (killed || over_memory) {
            kill(-pid, SIGKILL);
            wait4(pid, &status, 0, &ru);
            break;
        }
        {   struct timespec nap;
            nap.tv_sec = 0;
            nap.tv_nsec = 200000;   /* 0.2ms: fine enough for a 25ms limit */
            nanosleep(&nap, NULL);
        }
    }

    if (peak < (long long)ru.ru_maxrss) peak = ru.ru_maxrss;
    if ((f = fopen(report, "w")) != NULL) {
        fprintf(f, "%d %d %lld %lld %lld %d\n", killed, over_memory,
                (long long)(ru.ru_utime.tv_sec * 1000000LL + ru.ru_utime.tv_usec
                          + ru.ru_stime.tv_sec * 1000000LL + ru.ru_stime.tv_usec),
                peak, ms_since(&t0), status);
        fclose(f);
    }
    kill(-pid, SIGKILL);            /* sweep anything PROG left behind */
    return 0;
}
"""


def measure_memory_floor(runner, cache_root):
    src = os.path.join(cache_root, "floor.cpp")
    with open(src, "w", encoding="utf-8") as f:
        f.write('#include <fstream>\n#include <vector>\n#include <string>\n'
                'int main(){ std::ifstream i("floor.in"); std::ofstream o("floor.out");'
                ' std::string s; i >> s; o << s << 1 << "\\n"; }\n')
    binary = os.path.join(cache_root, "floor")
    ok, _ = _run_compiler(["g++", "-std=c++17", "-O2", "-static", "-w",
                           "-o", binary, src], cache_root)
    if not ok:
        return 0
    floor = 0
    for _ in range(3):
        floor = max(floor, run_limited(runner, [binary], cache_root, 5, 5, None).maxrss_kb)
    return floor


def build_runner(cache_root):
    src = os.path.join(cache_root, "runner.c")
    binary = os.path.join(cache_root, "runner")
    with open(src, "w", encoding="utf-8") as f:
        f.write(RUNNER_C)
    ok, out = _run_compiler(["gcc", "-O2", "-w", "-o", binary, src], cache_root)
    if not ok:
        sys.exit(f"error: cannot build the process supervisor:\n{out}")
    return binary


def parse_time_limit(text):
    m = re.search(r"([0-9]*\.?[0-9]+)", text or "")
    return float(m.group(1)) if m else 1.0


def parse_memory_limit(text):
    m = re.search(r"(\d+)", text or "")
    return int(m.group(1)) if m else 65536


class Run:
    __slots__ = ("cpu", "wall", "maxrss_kb", "exitcode", "signum", "timed_out",
                 "over_memory")

    def __init__(self, cpu, wall, maxrss_kb, exitcode, signum, timed_out,
                 over_memory=False):
        self.cpu = cpu
        self.wall = wall
        self.maxrss_kb = maxrss_kb
        self.exitcode = exitcode
        self.signum = signum
        self.timed_out = timed_out
        self.over_memory = over_memory


def _kill_group(pid):
    for killer in (lambda: os.killpg(pid, signal.SIGKILL),
                   lambda: os.kill(pid, signal.SIGKILL)):
        try:
            killer()
            return
        except (ProcessLookupError, PermissionError):
            continue


def _read_report(path):
    try:
        with open(path, encoding="ascii", errors="replace") as f:
            text = f.read().split()
    except OSError:
        return None
    if len(text) != 6 or text[0] == "PID":
        return None
    try:
        killed, over_mem, cpu_us, maxrss_kb, wall_ms, status = (int(v) for v in text)
    except ValueError:
        return None
    return killed, over_mem, cpu_us / 1e6, maxrss_kb, wall_ms / 1000.0, status


def _reported_pid(path):
    try:
        with open(path, encoding="ascii", errors="replace") as f:
            parts = f.read().split()
        if len(parts) == 2 and parts[0] == "PID":
            return int(parts[1])
    except (OSError, ValueError):
        pass
    return None


def run_limited(runner, argv, cwd, cpu_limit, wall_limit, as_bytes,
                rss_limit_kb=0, out_path=None):
    report = os.path.join(cwd, ".runner-report")
    cmd = [runner, report, str(int(wall_limit * 1000)),
           str(max(1, int(math.ceil(cpu_limit)))), str(int(as_bytes or 0)),
           str(FSIZE_CAP), str(int(rss_limit_kb)),
           out_path or os.devnull] + list(argv)

    start = time.monotonic()
    proc = subprocess.Popen(cmd, cwd=cwd, start_new_session=True,
                            stdin=subprocess.DEVNULL,
                            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    outer = start + wall_limit + OUTER_GRACE
    delay = 0.0005
    while proc.poll() is None:
        now = time.monotonic()
        if now >= outer:
            _kill_group(proc.pid)
            stray = _reported_pid(report)
            if stray:
                _kill_group(stray)
            proc.wait()
            break
        time.sleep(min(delay, max(0.0, outer - now)))
        delay = min(delay * 1.5, 0.02)

    wall = time.monotonic() - start
    parsed = _read_report(report)
    if parsed is None:
        return Run(wall, wall, 0, None, signal.SIGKILL, True)
    killed, over_mem, cpu, maxrss_kb, inner_wall, status = parsed
    signum = os.WTERMSIG(status) if os.WIFSIGNALED(status) else None
    code = os.WEXITSTATUS(status) if os.WIFEXITED(status) else None
    return Run(cpu, inner_wall, maxrss_kb, code, signum, bool(killed),
               bool(over_mem))


JAVA_CLASS_RE = re.compile(r"(?:^|\s)public\s+(?:final\s+|abstract\s+)?class\s+(\w+)", re.M)
ANY_CLASS_RE = re.compile(r"(?:^|\s)class\s+(\w+)", re.M)


def _run_compiler(cmd, cwd):
    try:
        p = subprocess.run(cmd, cwd=cwd, stdout=subprocess.PIPE,
                           stderr=subprocess.STDOUT, timeout=COMPILE_TIMEOUT)
    except subprocess.TimeoutExpired:
        return False, f"compiler timed out after {COMPILE_TIMEOUT}s"
    except OSError as exc:
        return False, f"cannot run {cmd[0]}: {exc}"
    return p.returncode == 0, p.stdout.decode("utf-8", "replace")


def compile_source(lang, code, workdir, mem_kb):
    if lang in ("cpp", "c"):
        src = os.path.join(workdir, "sol." + ("cpp" if lang == "cpp" else "c"))
        binary = os.path.join(workdir, "sol")
        with open(src, "w", encoding="utf-8") as f:
            f.write(code)
        if lang == "c":
            ok, out = _run_compiler(
                ["gcc", "-O2", "-static", "-w", "-o", binary, src, "-lm"], workdir)
            return ([binary], None) if ok else (None, out)
        last = ""
        for std in CXX_STDS:
            ok, out = _run_compiler(
                ["g++", f"-std={std}", "-O2", "-static", "-w", "-o", binary, src],
                workdir)
            if ok:
                return [binary], None
            last = out
        return None, last

    if lang == "java":
        m = JAVA_CLASS_RE.search(code) or ANY_CLASS_RE.search(code)
        if not m:
            return None, "no class declaration found in source"
        cls = m.group(1)
        src = os.path.join(workdir, cls + ".java")
        with open(src, "w", encoding="utf-8") as f:
            f.write(code)
        ok, out = _run_compiler(["javac", "-nowarn", "-d", workdir, src], workdir)
        if not ok:
            return None, out
        java = shutil.which("java")
        if not java:
            return None, "java runtime not found"
        heap = max(mem_kb, 262144)
        return [java, f"-Xmx{heap}k", "-XX:+UseSerialGC", "-cp", workdir, cls], None

    return None, f"unsupported language: {lang}"


def same_output(produced_path, expected_path):
    try:
        with open(produced_path, "rb") as f:
            got = f.read().split()
        with open(expected_path, "rb") as f:
            want = f.read().split()
    except OSError:
        return False
    return got == want


class Test:
    __slots__ = ("num", "in_path", "ok_path")

    def __init__(self, num, in_path, ok_path):
        self.num = num
        self.in_path = in_path
        self.ok_path = ok_path


class Prepared:
    def __init__(self, name, tests, evaluator, time_limit, mem_kb, layout, values,
                 test_values):
        self.name = name
        self.tests = tests
        self.evaluator = evaluator
        self.time_limit = time_limit
        self.mem_kb = mem_kb
        self.layout = layout
        self.values = values
        self.test_values = test_values


TEST_RE = re.compile(r"^grader_test(\d+)\.(in|ok)$")


class Archive:
    def __init__(self, zip_path):
        self.zip_path = zip_path
        self.name = os.path.basename(zip_path)[:-4]
        self.zf = zipfile.ZipFile(zip_path)
        self.names = self.zf.namelist()
        self.root = self._detect_root()

    def _detect_root(self):
        tops = {n.split("/", 1)[0] for n in self.names if "/" in n}
        return self.name if self.name in tops or not tops else sorted(tops)[0]

    def close(self):
        self.zf.close()

    def _path(self, rel):
        return f"{self.root}/{rel}"

    def read(self, rel):
        return self.zf.read(self._path(rel))

    def has(self, rel):
        return self._path(rel) in self.names

    def limits(self):
        meta = json.loads(self.read(f"{self.name}.json").decode("utf-8", "replace"))
        return parse_time_limit(meta.get("time_limit")), \
            parse_memory_limit(meta.get("memory_limit"))

    def test_entries(self):
        ins, oks = {}, {}
        for n in self.names:
            if f"/{self.root}/" in "/" + n and "/tests/" in n:
                m = TEST_RE.match(n.rsplit("/", 1)[1])
                if m:
                    (ins if m.group(2) == "in" else oks)[int(m.group(1))] = n
        return [(num, ins[num], oks.get(num)) for num in sorted(ins)]

    def evaluator_entry(self):
        rel = "tests/grader_eval.cpp"
        return self._path(rel) if self.has(rel) else None

    def subtask_layout(self, max_files=400):
        layout, values, test_values = {}, {}, {}
        details = [n for n in self.names if "/details/" in n and n.endswith(".csv")]
        ntests = len(self.test_entries())
        for n in details[:max_files]:
            text = self.zf.read(n).decode("utf-8", "replace")
            for r in csv.DictReader(io.StringIO(text)):
                try:
                    t, s, p = int(r["test"]), int(r["subtask"]), int(r["subtask_points"])
                except (TypeError, ValueError, KeyError):
                    continue
                layout[t] = s
                values[s] = max(values.get(s, 0), p)
                try:
                    tp = int(r["test_points"])
                except (TypeError, ValueError, KeyError):
                    continue
                test_values[t] = max(test_values.get(t, 0), tp)
            if sum(values.values()) == 100 and len(layout) >= ntests:
                break
        if not layout or sum(values.values()) != 100:
            return None, None, None
        return layout, values, test_values

    def submissions(self):
        by_id = {}
        for n in self.names:
            if "/submissions/" in n and n.endswith(".json"):
                sid = n.rsplit("/", 1)[1][:-5].rsplit("_", 1)[-1]
                by_id[sid] = n
        def by_number(kv):
            return (0, int(kv[0]), "") if kv[0].isdigit() else (1, 0, kv[0])

        out, skipped = [], 0
        for sid, entry in sorted(by_id.items(), key=by_number):
            try:
                d = json.loads(self.zf.read(entry).decode("utf-8", "replace"))
            except (ValueError, KeyError):
                continue
            lang = (d.get("language") or "").strip().lower()
            code = d.get("code") or ""
            if lang not in LANGS or not code.strip():
                skipped += 1
                continue
            out.append((sid, lang, code))
        return out, skipped

    def recorded_scores(self):
        try:
            text = self.read(f"{self.name}.csv").decode("utf-8", "replace")
        except KeyError:
            return {}
        scores = {}
        for r in csv.DictReader(io.StringIO(text)):
            try:
                scores[r["id"]] = int(r["score"])
            except (TypeError, ValueError, KeyError):
                pass
        return scores

    def judged_locally(self):
        return {n.rsplit("/", 1)[1][:-4] for n in self.names
                if "/details_local/" in n and n.endswith(".csv")}


def prepare(arc, cache_root, opts):
    tdir = os.path.join(cache_root, arc.name)
    os.makedirs(tdir, exist_ok=True)
    tests = []
    for num, in_entry, ok_entry in arc.test_entries():
        in_path = os.path.join(tdir, f"{num}.in")
        with open(in_path, "wb") as f:
            f.write(arc.zf.read(in_entry))
        os.chmod(in_path, 0o444)
        ok_path = None
        if ok_entry:
            ok_path = os.path.join(tdir, f"{num}.ok")
            with open(ok_path, "wb") as f:
                f.write(arc.zf.read(ok_entry))
            os.chmod(ok_path, 0o444)
        tests.append(Test(num, in_path, ok_path))

    evaluator = None
    entry = arc.evaluator_entry()
    if entry:
        src = os.path.join(tdir, "grader_eval.cpp")
        with open(src, "wb") as f:
            f.write(arc.zf.read(entry))
        binary = os.path.join(tdir, "grader_eval")
        ok, out = _run_compiler(["g++", "-O2", "-w", "-o", binary, src], tdir)
        if ok:
            evaluator = binary
        else:
            print(f"warning: {arc.name}: evaluator failed to build, falling back "
                  f"to .ok comparison\n{out.strip()[:400]}", file=sys.stderr)

    time_limit, mem_kb = arc.limits()
    layout, values, test_values = arc.subtask_layout()
    if layout is None:
        n = len(tests) or 1
        layout = {t.num: i + 1 for i, t in enumerate(tests)}
        base, extra = divmod(100, n)
        values = {i + 1: base + (1 if i < extra else 0) for i in range(n)}
        test_values = {}
        if opts["verbose"]:
            print(f"note: {arc.name}: no subtask layout in details/, "
                  f"using {n} equal subtasks", file=sys.stderr)

    sizes = {}
    for t in layout.values():
        sizes[t] = sizes.get(t, 0) + 1
    for num, sub in layout.items():
        if num not in test_values and sizes.get(sub) == 1:
            test_values[num] = values.get(sub, 0)

    return Prepared(arc.name, tests, evaluator, time_limit, mem_kb, layout, values,
                    test_values)


def run_evaluator(prep, workdir, opts):
    log = os.path.join(workdir, "_eval.log")
    run = run_limited(opts["runner"], [prep.evaluator], workdir, EVAL_TIME_LIMIT,
                      EVAL_TIME_LIMIT + 5, None, out_path=log)
    try:
        with open(log, encoding="utf-8", errors="replace") as f:
            raw = f.read()
    except OSError:
        raw = ""
    if run.timed_out:
        return 0, "Evaluator timp depasit"
    m = re.search(r"(-?\d+)\s*$", raw.strip())
    points = int(m.group(1)) if m else 0
    message = raw[:m.start()].strip() if m else raw.strip()
    message = " ".join(message.split())[:120] or ("Corect" if points > 0 else "Gresit")
    return points, message


def judge_tests(prep, argv, lang, workdir, opts):
    eff_limit = prep.time_limit * opts["time_factor"]
    wall_limit = eff_limit + (opts["java_grace"] if lang == "java" else opts["grace"])
    as_bytes = None if lang == "java" else opts["as_cap"] * 1024 * 1024
    rss_limit = 0 if lang == "java" else prep.mem_kb
    floor = 0 if lang == "java" else opts["mem_baseline"]
    rows = []

    for test in prep.tests:
        rundir = tempfile.mkdtemp(prefix="t", dir=workdir)
        in_file = os.path.join(rundir, f"{prep.name}.in")
        out_file = os.path.join(rundir, f"{prep.name}.out")
        try:
            os.link(test.in_path, in_file)
        except OSError:
            shutil.copyfile(test.in_path, in_file)

        run = run_limited(opts["runner"], argv, rundir, eff_limit, wall_limit,
                          as_bytes,
                          rss_limit_kb=(rss_limit + floor) if rss_limit else 0)

        used_kb = max(0, run.maxrss_kb - floor)
        over_memory = run.over_memory or (rss_limit and used_kb > rss_limit)

        awarded = None

        if over_memory:
            message, ok, correct = "Memory limit exceeded", False, False
        elif run.timed_out or run.cpu > eff_limit:
            message, ok, correct = "Time limit exceeded", False, False
        elif run.signum is not None:
            message = f"Killed by Signal {run.signum}"
            ok = correct = False
        elif run.exitcode:
            message = f"Non zero exit status: {run.exitcode}"
            ok = correct = False
        elif not os.path.exists(out_file):
            message, ok, correct = "Fisier de iesire lipsa", False, False
        elif prep.evaluator:
            if test.ok_path:
                try:
                    os.link(test.ok_path, os.path.join(rundir, f"{prep.name}.ok"))
                except OSError:
                    shutil.copyfile(test.ok_path,
                                    os.path.join(rundir, f"{prep.name}.ok"))
            points, message = run_evaluator(prep, rundir, opts)
            correct = points > 0
            ok = correct
            awarded = points
        elif test.ok_path and same_output(out_file, test.ok_path):
            message, ok, correct = "OK", True, True
        else:
            message, ok, correct = "Incorect", False, False

        if awarded is None:
            value = prep.test_values.get(test.num)
            awarded = 0 if not correct else ("" if value is None else value)

        rows.append({
            "test": test.num,
            "subtask": prep.layout.get(test.num, test.num),
            "time": f"{int(round(run.cpu * 1000))}ms",
            "memory": f"{used_kb}kb",
            "message": message,
            "ok": ok,
            "correct": correct,
            "test_points": awarded,
        })
        shutil.rmtree(rundir, ignore_errors=True)

        if opts["stop_early"] and not correct:
            break
    return rows


def award_subtasks(prep, rows):
    passed = {}
    for r in rows:
        s = r["subtask"]
        passed[s] = passed.get(s, True) and r["correct"]
    for r in rows:
        s = r["subtask"]
        r["subtask_points"] = prep.values.get(s, 0) if passed.get(s) else 0
    return sum(prep.values.get(s, 0) for s, won in passed.items() if won)


def rows_to_csv(sid, rows):
    buf = io.StringIO()
    w = csv.writer(buf, lineterminator="\n")
    w.writerow(DETAILS_HEADER)
    for r in rows:
        w.writerow([sid, r["test"], r["subtask"], r["time"], r["memory"],
                    r["message"], "YES" if r["ok"] else "NO", r["test_points"],
                    r["subtask_points"]])
    return buf.getvalue()


def judge_submission(prep, sid, lang, code, opts):
    workdir = tempfile.mkdtemp(prefix=f"judge-{prep.name}-{sid}-")
    try:
        argv, err = compile_source(lang, code, workdir, prep.mem_kb)
        if argv is None:
            first = " ".join((err or "").split())[:100]
            return rows_to_csv(sid, []), 0, f"compile error: {first}"
        rows = judge_tests(prep, argv, lang, workdir, opts)
        score = award_subtasks(prep, rows)
        return rows_to_csv(sid, rows), score, ""
    finally:
        shutil.rmtree(workdir, ignore_errors=True)


_PREP = None


def _worker_init(prep, opts):
    global _PREP
    _PREP = (prep, opts)


def _worker_judge(job):
    sid, lang, code = job
    prep, opts = _PREP
    try:
        text, score, note = judge_submission(prep, sid, lang, code, opts)
    except Exception as exc:
        return sid, None, 0, f"{type(exc).__name__}: {exc}"
    return sid, text, score, note


def store_results(zip_path, root, results, wipe=False):
    if not results and not wipe:
        return
    prefix = f"{root}/details_local/"
    payload = {prefix + f"{sid}.csv": text for sid, text in results.items()}
    with zipfile.ZipFile(zip_path) as zf:
        existing = set(zf.namelist())
    stale = {n for n in existing if n.startswith(prefix)} if wipe else set()
    clashes = (set(payload) & existing) | stale

    if not clashes:
        with zipfile.ZipFile(zip_path, "a", zipfile.ZIP_DEFLATED) as zf:
            for name, text in payload.items():
                zf.writestr(name, text)
        return

    fd, tmp = tempfile.mkstemp(dir=os.path.dirname(zip_path) or ".", suffix=".zip")
    os.close(fd)
    try:
        with zipfile.ZipFile(zip_path) as src, \
                zipfile.ZipFile(tmp, "w", zipfile.ZIP_DEFLATED) as dst:
            for info in src.infolist():
                if info.filename in payload or info.filename in stale:
                    continue
                dst.writestr(info, src.read(info.filename))
            for name, text in payload.items():
                dst.writestr(name, text)
        os.replace(tmp, zip_path)
    except BaseException:
        if os.path.exists(tmp):
            os.unlink(tmp)
        raise


def select_jobs(arc, opts):
    subs, other_lang = arc.submissions()
    if opts["ids"]:
        wanted = set(opts["ids"])
        subs = [s for s in subs if s[0] in wanted]
        missing = wanted - {s[0] for s in subs}
        if missing:
            print(f"warning: {arc.name}: not found or not c/cpp/java: "
                  f"{sorted(missing)}", file=sys.stderr)
    already = 0
    if not (opts["force"] or opts["reset"]):
        done = arc.judged_locally()
        before = len(subs)
        subs = [s for s in subs if s[0] not in done]
        already = before - len(subs)
    if opts["limit"]:
        subs = subs[:opts["limit"]]
    return subs, other_lang, already


def process_problem(zip_path, opts, cache_root):
    arc = Archive(zip_path)
    try:
        jobs, other_lang, already = select_jobs(arc, opts)
        note = []
        if already:
            note.append(f"{already} already judged")
        if other_lang:
            note.append(f"{other_lang} not c/cpp/java")
        suffix = f" ({', '.join(note)} skipped)" if note else ""
        print(f"\n=== {arc.name}: {len(jobs)} submission(s){suffix} ===",
              file=sys.stderr)
        if not jobs:
            return 0, 0
        prep = prepare(arc, cache_root, opts)
        if not prep.tests:
            print(f"error: {arc.name}: no tests in the archive", file=sys.stderr)
            return 0, len(jobs)
        recorded = arc.recorded_scores() if opts["verify"] else {}
        root = arc.root
    finally:
        arc.close()

    kind = "evaluator" if prep.evaluator else ".ok compare"
    print(f"    {len(prep.tests)} tests, {kind}, limit {prep.time_limit}s / "
          f"{prep.mem_kb}kb", file=sys.stderr)

    results, judged, failed, mismatches = {}, 0, 0, 0

    def absorb(sid, text, score, note):
        nonlocal judged, failed, mismatches
        if text is None:
            failed += 1
            print(f"    ! {sid}: {note}", file=sys.stderr)
            return
        results[sid] = text
        judged += 1
        line = ""
        if opts["verify"] and sid in recorded:
            want = recorded[sid]
            if want != score:
                mismatches += 1
                line = f"    {sid}: local {score} vs recorded {want}  MISMATCH"
            elif opts["verbose"]:
                line = f"    {sid}: {score} (matches)"
        elif opts["verbose"]:
            line = f"    {sid}: {score}" + (f"  [{note}]" if note else "")
        if line:
            print(line, file=sys.stderr)

    wipe_pending = opts["reset"]

    def flush():
        nonlocal wipe_pending
        if (results or wipe_pending) and not opts["dry_run"]:
            store_results(zip_path, root, results, wipe=wipe_pending)
            wipe_pending = False
        results.clear()

    try:
        if opts["jobs"] > 1:
            with concurrent.futures.ProcessPoolExecutor(
                    max_workers=opts["jobs"], initializer=_worker_init,
                    initargs=(prep, opts)) as pool:
                for sid, text, score, note in pool.map(_worker_judge, jobs,
                                                       chunksize=1):
                    absorb(sid, text, score, note)
                    if len(results) >= opts["flush_every"]:
                        flush()
        else:
            _worker_init(prep, opts)
            for job in jobs:
                sid, text, score, note = _worker_judge(job)
                absorb(sid, text, score, note)
                if len(results) >= opts["flush_every"]:
                    flush()
    finally:
        flush()

    where = "(dry run, nothing written)" if opts["dry_run"] else \
        f"-> {os.path.basename(zip_path)}:{root}/details_local/"
    extra = f", {mismatches} score mismatch(es)" if opts["verify"] else ""
    print(f"    {judged} judged, {failed} failed{extra} {where}", file=sys.stderr)
    return judged, failed


def judge_local_file(zip_path, path, opts, cache_root):
    arc = Archive(zip_path)
    try:
        prep = prepare(arc, cache_root, opts)
    finally:
        arc.close()
    ext = os.path.splitext(path)[1].lower()
    lang = {".c": "c", ".java": "java"}.get(ext, "cpp")
    with open(path, encoding="utf-8", errors="replace") as f:
        code = f.read()
    _worker_init(prep, opts)
    text, score, note = judge_submission(prep, "local", lang, code, opts)
    if note:
        print(note, file=sys.stderr)
    sys.stdout.write(text)
    print(f"\nscore: {score}/100", file=sys.stderr)
    return 0 if score else 1


def discover(base_dir):
    if not os.path.isdir(base_dir):
        sys.exit(f"error: no such directory: {base_dir}")
    return sorted(os.path.splitext(fn)[0] for fn in os.listdir(base_dir)
                  if fn.lower().endswith(".zip"))


def main():
    ap = argparse.ArgumentParser(
        description="Evaluate archived infoarena submissions locally and store "
                    "the verdicts in each zip's details_local/ folder.")
    ap.add_argument("problem", nargs="*",
                    help="problem slug(s); omit to sweep every <base-dir>/*.zip")
    ap.add_argument("--base-dir", default="infoarena",
                    help="directory holding <problem>.zip (default: infoarena)")
    ap.add_argument("--submission", "-s", action="append", metavar="ID",
                    help="judge only this submission id (repeatable)")
    ap.add_argument("--limit", type=int, metavar="N",
                    help="judge at most N submissions per problem")
    ap.add_argument("--force", action="store_true",
                    help="re-judge submissions that already have a "
                         "details_local/ entry (default: skip them, so a long "
                         "run can be resumed). Overwrites the ones it reaches "
                         "and leaves any others in place")
    ap.add_argument("--reset", action="store_true",
                    help="start from nothing: empty each selected problem's "
                         "details_local/ and judge every submission again, so "
                         "results from earlier runs cannot survive alongside the "
                         "new ones. Cannot be narrowed with --limit or "
                         "--submission -- use --force for that")
    ap.add_argument("--jobs", "-j", type=int, default=1, metavar="N",
                    help="judge N submissions in parallel (default: 1). Verdicts "
                         "use CPU time so they hold up under load, but keep N at "
                         "or below your core count or the wall-clock watchdog "
                         "may call a slow test a timeout")
    ap.add_argument("--time-factor", type=float, default=3.0, metavar="F",
                    help="multiply every problem's time limit by F, for verdict "
                         "and deadline alike (default: 3.0, deliberately "
                         "generous -- see README.md; pass 1.0 for the "
                         "limit exactly as stated)")
    ap.add_argument("--grace", type=float, default=0.15, metavar="S",
                    help="seconds allowed on top of the time limit before a "
                         "native program is killed (default: 0.15)")
    ap.add_argument("--java-grace", type=float, default=2.0, metavar="S",
                    help="same, for java, which pays JVM startup (default: 2.0)")
    ap.add_argument("--as-cap", type=int, default=0, metavar="MB",
                    help="also cap a program's address space at MB. Off by "
                         "default: reserving address space costs no memory and "
                         "submissions do it freely, so capping it fails programs "
                         "infoarena passes. Resident memory is what gets "
                         "enforced (default: 0, meaning no cap)")
    ap.add_argument("--mem-baseline", type=int, default=-1, metavar="KB",
                    help="memory to discount as the toolchain's own footprint "
                         "rather than the submission's; default is to measure it "
                         "by running an empty program, 0 charges it to the "
                         "submission")
    ap.add_argument("--stop-early", action="store_true",
                    help="stop a submission at its first failed test (faster, "
                         "but the remaining tests get no row)")
    ap.add_argument("--verify", action="store_true",
                    help="compare each local score with the archive's recorded "
                         "score and report mismatches")
    ap.add_argument("--code", metavar="FILE",
                    help="judge this source file instead of the archive's "
                         "submissions; prints the result, writes nothing")
    ap.add_argument("--dry-run", action="store_true",
                    help="judge but do not write into any zip")
    ap.add_argument("--flush-every", type=int, default=200, metavar="N",
                    help="write results into the zip every N submissions "
                         "(default: 200)")
    ap.add_argument("--verbose", "-v", action="store_true",
                    help="print a line per submission")
    args = ap.parse_args()

    if args.jobs < 1:
        sys.exit("error: --jobs must be at least 1")
    if args.reset and (args.limit or args.submission):
        sys.exit("error: --reset clears each problem's details_local/ and rebuilds "
                 "it in full, so it cannot be narrowed with --limit or "
                 "--submission. Use --force to re-judge a subset in place.")
    if args.reset and args.code:
        sys.exit("error: --reset has nothing to do with --code, which writes nothing")
    problems = args.problem or discover(args.base_dir)
    if args.code and len(problems) != 1:
        sys.exit("error: --code judges one problem; name exactly one slug")
    if not problems:
        sys.exit(f"error: no problem archives found in {args.base_dir}/")

    opts = {
        "ids": args.submission, "limit": args.limit, "force": args.force,
        "reset": args.reset,
        "jobs": args.jobs, "time_factor": args.time_factor, "grace": args.grace,
        "java_grace": args.java_grace, "as_cap": args.as_cap,
        "mem_baseline": max(0, args.mem_baseline),
        "stop_early": args.stop_early, "verify": args.verify,
        "dry_run": args.dry_run, "flush_every": args.flush_every,
        "verbose": args.verbose,
    }

    cache_root = tempfile.mkdtemp(prefix="infoarena-tests-")
    total_judged = total_failed = 0
    missing = []
    try:
        opts["runner"] = build_runner(cache_root)
        if args.mem_baseline < 0:
            opts["mem_baseline"] = measure_memory_floor(opts["runner"], cache_root)
            if args.verbose:
                print(f"note: discounting {opts['mem_baseline']}kb of toolchain "
                      f"footprint from each measurement", file=sys.stderr)
        if args.code:
            path = os.path.join(args.base_dir, problems[0] + ".zip")
            if not os.path.exists(path):
                sys.exit(f"error: no such archive: {path}")
            return judge_local_file(path, args.code, opts, cache_root)

        for slug in problems:
            path = os.path.join(args.base_dir, slug + ".zip")
            if not os.path.exists(path):
                print(f"error: no such archive: {path}", file=sys.stderr)
                missing.append(slug)
                continue
            try:
                judged, failed = process_problem(path, opts, cache_root)
            except Exception as exc:
                print(f"error: {slug}: {type(exc).__name__}: {exc}", file=sys.stderr)
                missing.append(slug)
                continue
            total_judged += judged
            total_failed += failed
    finally:
        shutil.rmtree(cache_root, ignore_errors=True)

    if len(problems) > 1 or missing:
        print(f"\n=== done: {total_judged} judged, {total_failed} failed ===",
              file=sys.stderr)
        if missing:
            print(f"    problems skipped: {missing}", file=sys.stderr)
    return 1 if (total_failed or missing) else 0


if __name__ == "__main__":
    sys.exit(main())
