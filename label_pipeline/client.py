import json
import os
import random
import re
import sys
import threading
import time

DEFAULT_BASE_URL = "https://api.deepseek.com"
DEFAULT_MODEL = "deepseek-chat"

_RETRYABLE = (429, 500, 502, 503, 504, 529)

_REASONING_HINTS = ("reasoner", "-r1", "r1-", "thinking", "think", "v4", "flash")

_STRICT_HINTS = ("reasoner", "-r1", "r1-")

_MAX_TOKENS = 32768

_THINKING_TOKENS = 16384

THINKING_MODES = ("auto", "on", "off")

REASONING_EFFORTS = ("auto", "minimal", "low", "medium", "high")


def is_reasoning(model):
    name = (model or "").lower()
    return any(hint in name for hint in _REASONING_HINTS)


def rejects_json_mode(model):
    name = (model or "").lower()
    return any(hint in name for hint in _STRICT_HINTS)


class Usage:
    def __init__(self):
        self.lock = threading.Lock()
        self.prompt = 0
        self.cached = 0
        self.completion = 0
        self.calls = 0

    def add(self, usage):
        if usage is None:
            return
        with self.lock:
            self.calls += 1
            self.prompt += getattr(usage, "prompt_tokens", 0) or 0
            self.completion += getattr(usage, "completion_tokens", 0) or 0
            self.cached += getattr(usage, "prompt_cache_hit_tokens", 0) or 0

    def summary(self):
        with self.lock:
            return {"calls": self.calls, "prompt_tokens": self.prompt,
                    "cached_prompt_tokens": self.cached,
                    "completion_tokens": self.completion}


class DeepSeekClient:
    def __init__(self, model=DEFAULT_MODEL, base_url=None, api_key=None,
                 max_retries=6, timeout=120.0, temperature=0.0, max_tokens=0,
                 thinking="auto", reasoning_effort="auto"):
        from openai import OpenAI

        key = api_key or os.environ.get("DEEPSEEK_API_KEY")
        if not key and base_url:
            key = "not-needed"
        if not key:
            raise RuntimeError(
                "DEEPSEEK_API_KEY is not set. Export it, pass --base-url to reach "
                "a self-hosted endpoint, or run with --mock to exercise the "
                "pipeline without calling the API.")
        self.client = OpenAI(base_url=base_url or DEFAULT_BASE_URL, api_key=key,
                             timeout=timeout)
        self.model = model
        self.max_retries = max_retries
        self.temperature = temperature
        self.reasoning = is_reasoning(model)
        self.strict = rejects_json_mode(model)
        self.thinking = thinking
        self.reasoning_effort = reasoning_effort
        thinks = self.reasoning and thinking != "off"
        self.max_tokens = max_tokens or (_THINKING_TOKENS if thinks else 200)
        self.pinned = bool(max_tokens)
        self._thinking_ok = True
        self._effort_ok = True
        self.usage = Usage()

    def complete_json(self, system, user, max_tokens=None):
        last = None
        budget = max_tokens or self.max_tokens
        for attempt in range(self.max_retries):
            try:
                kwargs = {
                    "model": self.model,
                    "messages": [{"role": "system", "content": system},
                                 {"role": "user", "content": user}],
                    "max_tokens": budget,
                }
                if not self.strict:
                    kwargs["response_format"] = {"type": "json_object"}
                    kwargs["temperature"] = self.temperature
                if self.thinking in ("on", "off") and self._thinking_ok:
                    kwargs["extra_body"] = {
                        "thinking": {"type": "enabled" if self.thinking == "on"
                                     else "disabled"}}
                if (self.reasoning_effort != "auto" and self._effort_ok
                        and self.thinking != "off"):
                    kwargs["reasoning_effort"] = self.reasoning_effort
                response = self.client.chat.completions.create(**kwargs)
                self.usage.add(response.usage)
                choice = response.choices[0]
                content = choice.message.content
                try:
                    return _parse_json(content)
                except ValueError:
                    ran_out = (choice.finish_reason == "length"
                               or not (content or "").strip())
                    if (self.pinned and not max_tokens) or not ran_out \
                            or budget >= _MAX_TOKENS:
                        raise
                    budget = min(_MAX_TOKENS, budget * 4)
                    self._raise_budget(budget)
                    continue
            except Exception as exc:
                last = exc
                if self._effort_ok and _rejects(exc, "reasoning_effort"):
                    self._effort_ok = False
                    budget = max_tokens or self.max_tokens
                    print("  %s does not accept reasoning_effort; ignoring it"
                          % self.model, file=sys.stderr)
                    continue
                if self._thinking_ok and _rejects_thinking(exc):
                    self._thinking_ok = False
                    budget = max_tokens or self.max_tokens
                    print("  %s does not accept a thinking parameter; ignoring "
                          "--thinking" % self.model, file=sys.stderr)
                    continue
                if not _retryable(exc) or attempt == self.max_retries - 1:
                    raise
                time.sleep(min(60.0, 2.0 ** attempt) * (0.5 + random.random()))
        raise last

    def _raise_budget(self, budget):
        with self.usage.lock:
            if budget <= self.max_tokens:
                return
            self.max_tokens = budget
        print("  %s ran out of completion budget; raising it to %d tokens "
              "(pin it with --max-tokens)" % (self.model, budget), file=sys.stderr)


def _rejects(exc, parameter):
    status = getattr(exc, "status_code", None) or getattr(
        getattr(exc, "response", None), "status_code", None)
    if status not in (400, 422):
        return False
    text = str(exc).lower()
    return parameter in text or "unexpected keyword argument" in text


def _rejects_thinking(exc):
    return _rejects(exc, "thinking")


def _retryable(exc):
    status = getattr(exc, "status_code", None) or getattr(
        getattr(exc, "response", None), "status_code", None)
    if status in _RETRYABLE:
        return True
    return exc.__class__.__name__ in (
        "RateLimitError", "APIConnectionError", "APITimeoutError",
        "InternalServerError", "APIStatusError")


_EXPECTED_KEYS = ("algorithm", "canonical")


def _parse_json(text):
    text = (text or "").strip()
    if text.startswith("```"):
        text = re.sub(r"^```[a-zA-Z]*\s*|\s*```$", "", text).strip()
    try:
        return json.loads(text)
    except json.JSONDecodeError:
        pass

    decoder = json.JSONDecoder()
    fallback = None
    for match in re.finditer(r"\{", text):
        try:
            obj, _end = decoder.raw_decode(text[match.start():])
        except json.JSONDecodeError:
            continue
        if isinstance(obj, dict):
            if any(k in obj for k in _EXPECTED_KEYS):
                return obj
            fallback = fallback or obj
    if fallback is not None:
        return fallback
    raise ValueError("no JSON object in model reply: %r" % text[:300])


_MOCK_RULES = [
    (r"\bpush[_\s-]*relabel\b|\bexcess\b.*\bheight\b", "Push-Relabel"),
    (r"\bdinic\b|\bniv\[|\blevel\[.*\bdfs\b", "Dinic"),
    (r"\bedmonds\b|\bkarp\b", "Edmonds-Karp"),
    (r"\bhopcroft\b", "Hopcroft-Karp"),
    (r"\bkruskal\b", "Kruskal"),
    (r"\bprim\b", "Prim"),
    (r"\bdijkstra\b", "Dijkstra"),
    (r"\bbellman\b", "Bellman-Ford"),
    (r"\baho\b|\bgoto\[|\bfail\[", "Aho-Corasick"),
    (r"\bkmp\b|\bprefix_function\b", "Knuth-Morris-Pratt"),
    (r"\bgcd\b|\beuclid\b|\bcmmdc\b", "Euclid extins"),
]


class MockClient:
    def __init__(self, model="mock", **_kwargs):
        self.model = model
        self.usage = Usage()

    def complete_json(self, system, user, max_tokens=None):
        body = user.lower()
        algorithm = "brute force"
        for pattern, name in _MOCK_RULES:
            if re.search(pattern, body):
                algorithm = name
                break
        unoptimized = bool(re.search(r"while\s*\(.{0,40}bfs\s*\(", body))
        self.usage.add(None)
        return {"algorithm": algorithm, "unoptimized": unoptimized,
                "confidence": 0.55}


def build_client(args):
    if args.mock:
        return MockClient()
    return DeepSeekClient(model=args.model, base_url=args.base_url,
                          temperature=args.temperature,
                          max_tokens=getattr(args, "max_tokens", 0),
                          thinking=getattr(args, "thinking", "auto"),
                          reasoning_effort=getattr(args, "reasoning_effort",
                                                   "auto"))
