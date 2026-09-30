import difflib
import re
import unicodedata

SUFFIX = "neoptimizat"

_QUALIFIERS = re.compile(
    r"\b(ne)?optimi[sz]at[aă]?\b|\boptimi[sz]ed\b|\bunoptimi[sz]ed\b|\bnaive?\b|"
    r"\bnaiv[aă]?\b|\bslow\b|\blent[aă]?\b|\befficient\b|\beficient[aă]?\b|"
    r"\bbasic\b|\bsimple\b|\bsimplu\b|\bvariant[aă]?\b|\bversion\b|"
    r"\bmodifica(t|t[aă]|te)\b|\bmodified\b|\bimproved\b|\bimbunatatit[aă]?\b|"
    r"\balgorithm\b|\balgoritm(ul)?\b|\bmethod\b|\bmetod[aă]\b|\bapproach\b",
    re.IGNORECASE)

_SEPARATORS = re.compile(r"[\s_/]*[-‐-―−][\s_/]*")


def strip_diacritics(text):
    return "".join(c for c in unicodedata.normalize("NFD", text)
                   if unicodedata.category(c) != "Mn")


def clean(name):
    name = (name or "").strip()
    name = re.sub(r"^[\"'`\s]+|[\"'`\s.;,:]+$", "", name)
    name = _QUALIFIERS.sub(" ", name)
    name = _SEPARATORS.sub("-", name)
    name = re.sub(r"\s+", " ", name).strip(" -")
    return name


def key(name):
    return re.sub(r"[^a-z0-9]+", "", strip_diacritics(clean(name)).lower())


def compose(algorithm, unoptimized):
    algorithm = clean(algorithm)
    if not algorithm:
        return ""
    return "%s %s" % (algorithm, SUFFIX) if unoptimized else algorithm


def split(label):
    label = (label or "").strip()
    if not label:
        return "", False
    unoptimized = bool(re.search(r"\b(ne|un)optimi", strip_diacritics(label), re.I))
    return clean(label), unoptimized


class Vocabulary:
    CUTOFF = 0.87

    def __init__(self, canonical=(), aliases=None, variants=None):
        self.canonical = []
        self._by_key = {}
        self._aliases = {}
        self.variants = dict(variants or {})
        for name in canonical:
            self.add(name)
        for raw, target in (aliases or {}).items():
            self._aliases[key(raw)] = clean(target)

    def add(self, name):
        name = clean(name)
        if not name:
            return ""
        k = key(name)
        if k not in self._by_key:
            self._by_key[k] = name
            self.canonical.append(name)
        return self._by_key[k]

    def resolve(self, name, learn=True):
        name = clean(name)
        if not name:
            return ""
        k = key(name)
        if k in self._aliases:
            return self.add(self._aliases[k])
        if k in self._by_key:
            return self._by_key[k]
        near = difflib.get_close_matches(k, list(self._by_key), n=1,
                                         cutoff=self.CUTOFF)
        if near:
            resolved = self._by_key[near[0]]
            self._aliases[k] = resolved
            return resolved
        return self.add(name) if learn else name

    def to_dict(self):
        return {"canonical": list(self.canonical),
                "aliases": dict(self._aliases),
                "variants": dict(self.variants)}

    @classmethod
    def from_dict(cls, data):
        return cls(data.get("canonical", ()), data.get("aliases", {}),
                   data.get("variants", {}))
