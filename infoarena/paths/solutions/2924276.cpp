#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")

using namespace std;

class InParser {
private:
	FILE *fin;
	char *buff;
	int sp;

	char read_ch() {
		++sp;
		if (sp == 4096) {
			sp = 0;
			fread(buff, 1, 4096, fin);
		}
		return buff[sp];
	}

public:
	InParser(const char* nume) {
		fin = fopen(nume, "r");
		buff = new char[4096]();
		sp = 4095;
	}

	InParser& operator >> (int &n) {
		char c;
		while (!isdigit(c = read_ch()) && c != '-');
		int sgn = 1;
		if (c == '-') {
			n = 0;
			sgn = -1;
		} else {
			n = c - '0';
		}
		while (isdigit(c = read_ch())) {
			n = 10 * n + c - '0';
		}
		n *= sgn;
		return *this;
	}
};

class OutParser {

private:
    FILE *fout;
    char *buff;
    int sp;

    void write_ch(char ch) {
        if (sp == 50000) {
            fwrite(buff, 1, 50000, fout);
            sp = 0;
            buff[sp++] = ch;
        } else {
            buff[sp++] = ch;
        }
    }

public:
    OutParser(const char* name) {
        fout = fopen(name, "w");
        buff = new char[50000]();
        sp = 0;
    }

    ~OutParser() {
        fwrite(buff, 1, sp, fout);
        fclose(fout);
    }

    OutParser& operator << (long long vu64) {
        if (vu64 <= 9) {
            write_ch(vu64 + '0');
        } else {
            (*this) << (vu64 / 10);
            write_ch(vu64 % 10 + '0');
        }
        return *this;
    }

    OutParser& operator << (char ch) {
        write_ch(ch);
        return *this;
    }

    OutParser& operator << (const char *ch) {
        while (*ch) {
            write_ch(*ch);
            ++ch;
        }
        return *this;
    }
};

InParser fin("paths.in");
OutParser fout("paths.out");

const int kN = 1e5;
int n, k;
int64_t sumK, sol[1 + kN];
pair<int64_t, int> dmax[1 + kN];
vector<pair<int, int>> g[1 + kN];
set<pair<int64_t, int>> paths[1 + kN];
multiset<int64_t> low, big;

static inline void fix() {
  while ((int)big.size() < k && !low.empty()) {
    auto it = --low.end();
    big.emplace(*it);
    sumK += *it;
    low.erase(it);
  }

  if (low.empty() || big.empty()) {
    return;
  }

  int64_t last = *(--low.end()), first = *big.begin();
  while (first < last) {
    big.erase(big.begin());
    sumK -= first;

    low.erase(--low.end());

    big.emplace(last);
    sumK += last;

    low.emplace(first);

    last = *(--low.end());
    first = *big.begin();
  }
}

static inline void add(const int64_t &x) {
  if ((int)big.size() < k) {
    big.emplace(x);
    sumK += x;
  } else {
    low.emplace(x);
    fix();
  }
}

static inline void rem(const int64_t &x) {
  if (low.count(x)) {
    low.erase(low.find(x));
  } else {
    big.erase(big.find(x));
    sumK -= x;
    fix();
  }
}

void dfs1(const int &u, const int &par) {
  for (const auto &it : g[u]) {
    int v, w;
    tie(v, w) = it;

    if (v != par) {
      dfs1(v, u);

      if (paths[v].empty()) {
        paths[u].emplace(w, v);
      } else {
        paths[u].emplace((--paths[v].end())->first + w, v);
      }
    }
  }
}

void dfs2(const int &u, const int &par) {
  sol[u] = sumK;

  for (const auto &it : g[u]) {
    int v, w;
    tie(v, w) = it;

    if (v != par) {
      auto it1 = --paths[u].end();
      pair<int64_t, int> path1, removed{-1, -1};

      if (it1->second == v) {
        if ((int)paths[u].size() == 1) {
          path1 = {w, u};
        } else {
          auto it2 = --it1;
          path1 = {it2->first + w, u};
          removed = *it2;
        }
      } else {
        path1 = {it1->first + w, u};
        removed = *it1;
      }

      paths[v].emplace(path1);
      add(path1.first);
      if (removed.first != -1) {
        rem(removed.first);
      }

      pair<int64_t, int> path2{dmax[v].first + w, v};
      rem(path2.first);
      paths[v].emplace(dmax[v]);
      add(dmax[v].first);

      dfs2(v, u);

      rem(path1.first);
      if (removed.first != -1) {
        add(removed.first);
      }

      add(path2.first);
      rem(dmax[v].first);
    }
  }
}

int main() {

  fin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    fin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  dfs1(1, 0);

  for (int i = 1; i <= n; ++i) {
    if (!paths[i].empty()) {
      auto it = *(--paths[i].end());
      dmax[i] = it;
      if (i != 1) {
        paths[i].erase(it);
      }
    }

    for (const auto &it : paths[i]) {
      add(it.first);
    }

    while ((int)paths[i].size() > 1 + (i == 1)) {
      paths[i].erase(paths[i].begin());
    }
  }

  dfs2(1, 0);

  for (int i = 1; i <= n; ++i) {
    fout << sol[i] << '\n';
  }

  return 0;
}
