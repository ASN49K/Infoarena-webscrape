import hashlib
import json
import os
import re
import threading

_BLOCK_COMMENT = re.compile(r"/\*.*?\*/", re.S)


def code_hash(code):
    body = _BLOCK_COMMENT.sub(" ", code or "")
    body = re.sub(r"//[^\n]*", " ", body)
    body = re.sub(r"\s+", " ", body).strip()
    return hashlib.sha1(body.encode("utf-8", "replace")).hexdigest()


class ResultStore:
    def __init__(self, path):
        self.path = path
        self.lock = threading.Lock()
        self.by_id = {}
        self.by_hash = {}
        self._load()

    def _load(self):
        if not os.path.isfile(self.path):
            return
        with open(self.path, encoding="utf-8") as fh:
            for line in fh:
                line = line.strip()
                if not line:
                    continue
                try:
                    record = json.loads(line)
                except json.JSONDecodeError:
                    continue
                self._index(record)

    def _index(self, record):
        self.by_id[str(record["id"])] = record
        if record.get("hash") and not record.get("error"):
            self.by_hash.setdefault(record["hash"], record)

    def get(self, submission_id):
        return self.by_id.get(str(submission_id))

    def get_by_hash(self, digest):
        return self.by_hash.get(digest)

    def put(self, record):
        with self.lock:
            self._index(record)
            os.makedirs(os.path.dirname(self.path) or ".", exist_ok=True)
            with open(self.path, "a", encoding="utf-8") as fh:
                fh.write(json.dumps(record, ensure_ascii=False) + "\n")
                fh.flush()

    def labels(self):
        return {sid: r.get("label", "") for sid, r in self.by_id.items()
                if not r.get("error")}
