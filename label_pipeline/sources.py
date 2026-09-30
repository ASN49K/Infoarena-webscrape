import csv
import glob
import io
import json
import os
import zipfile

CSV_FIELDS = [
    "id", "user", "full_name", "problem", "size", "date", "score", "status",
    "language", "compiler", "source_file", "num_tests", "num_subtasks", "url",
    "label",
]


class ProblemSource:
    def __init__(self, root, name):
        self.root = root
        self.name = name
        self.dir = os.path.join(root, name)
        self.zip = os.path.join(root, name + ".zip")
        self.unpacked = os.path.isdir(self.dir)
        if not self.unpacked and not os.path.isfile(self.zip):
            raise FileNotFoundError("no directory or zip for problem %r" % name)
        self._zf = None
        self._sub_index = None
        self.fieldnames = list(CSV_FIELDS)
        self.hand_labels = []

    @property
    def zf(self):
        if self._zf is None:
            self._zf = zipfile.ZipFile(self.zip)
        return self._zf

    def close(self):
        if self._zf is not None:
            self._zf.close()
            self._zf = None

    def _read(self, rel):
        if self.unpacked:
            path = os.path.join(self.dir, rel)
            if not os.path.isfile(path):
                return None
            with open(path, encoding="utf-8", errors="replace") as fh:
                return fh.read()
        member = "%s/%s" % (self.name, rel)
        try:
            with self.zf.open(member) as fh:
                return io.TextIOWrapper(fh, "utf-8", errors="replace").read()
        except KeyError:
            return None

    def meta(self):
        raw = self._read("%s.json" % self.name)
        return json.loads(raw) if raw else {}

    def solution(self):
        raw = self._read("solution.txt")
        if raw is None:
            return None
        body = "\n".join(line for line in raw.splitlines()
                          if not line.startswith("#")).strip()
        return body or None

    def rows(self):
        raw = self._read("%s.csv" % self.name)
        if raw is None:
            raise FileNotFoundError("%s: missing %s.csv" % (self.name, self.name))
        out = []
        reader = csv.DictReader(io.StringIO(raw))
        header = [f for f in (reader.fieldnames or []) if f]
        self.fieldnames = header + [f for f in CSV_FIELDS if f not in header]
        for row in reader:
            for field in self.fieldnames:
                row.setdefault(field, "")
                if row[field] is None:
                    row[field] = ""
            out.append(row)
        if not any(row.get("label") for row in out):
            self._merge_hand_labels(out)
        return out

    def hand_label_files(self):
        own = os.path.abspath(os.path.join(self.dir, "%s.csv" % self.name))
        root = os.path.abspath(self.root)
        seen, found = set(), []
        for folder in (root, os.path.dirname(root)):
            for path in sorted(glob.glob(os.path.join(folder, self.name + "*.csv"))):
                real = os.path.abspath(path)
                if real == own or real in seen:
                    continue
                seen.add(real)
                found.append(real)
        return found

    def _merge_hand_labels(self, rows):
        by_id = {}
        for path in self.hand_label_files():
            try:
                with open(path, encoding="utf-8", errors="replace") as fh:
                    reader = csv.DictReader(fh)
                    if "label" not in (reader.fieldnames or []):
                        continue
                    for raw in reader:
                        sid = (raw.get("id") or "").strip()
                        label = (raw.get("label") or "").strip()
                        if sid and label:
                            by_id.setdefault(sid, (label, path))
            except OSError:
                continue
        if not by_id:
            return
        used = {}
        for row in rows:
            hit = by_id.get(str(row["id"]).strip())
            if hit:
                row["label"] = hit[0]
                used[hit[1]] = used.get(hit[1], 0) + 1
        self.hand_labels = sorted(used.items())

    def _submission_index(self):
        if self._sub_index is not None:
            return self._sub_index
        index = {}
        if self.unpacked:
            subdir = os.path.join(self.dir, "submissions")
            names = os.listdir(subdir) if os.path.isdir(subdir) else []
            for base in names:
                if base.endswith(".json"):
                    index[base[:-5].rsplit("_", 1)[-1]] = os.path.join(subdir, base)
        else:
            prefix = "%s/submissions/" % self.name
            for member in self.zf.namelist():
                if member.startswith(prefix) and member.endswith(".json"):
                    base = member[len(prefix):-5]
                    index[base.rsplit("_", 1)[-1]] = member
        self._sub_index = index
        return index

    def code(self, submission_id):
        target = self._submission_index().get(str(submission_id))
        if target is None:
            return None
        if self.unpacked:
            with open(target, encoding="utf-8", errors="replace") as fh:
                return json.load(fh).get("code")
        with self.zf.open(target) as fh:
            return json.load(io.TextIOWrapper(fh, "utf-8", errors="replace")).get("code")


def discover(root):
    names = set()
    for entry in os.listdir(root):
        path = os.path.join(root, entry)
        if entry.endswith(".zip"):
            names.add(entry[:-4])
        elif os.path.isdir(path) and os.path.isfile(os.path.join(path, entry + ".csv")):
            names.add(entry)
    return sorted(names)
