#pragma GCC optimize("Ofast,unroll-loops")
#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>

#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()

#define fi first
#define se second

#define lsb(x) (x & (-x))

using namespace std;

inline bool ckmin(int &a, int b) { if (a <= b) return false; else a = b; return true; }
inline bool ckmax(int &a, int b) { if (a >= b) return false; else a = b; return true; }

#ifdef LOCAL
ifstream fin("input.txt");
#define fout cout
#else
#define FILE_NAME "fmcm"
ifstream fin(FILE_NAME ".in");
ofstream fout(FILE_NAME ".out");
#define endl '\n'
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 355;
const int INF = 2e9+5;

struct Edge {
	int dest, cap, cost, other;	
};

int n, m, source, sink;
vector<Edge> g[NMAX];
int dist[NMAX], pi[NMAX], pi2[NMAX];
int vis[NMAX];
bool inq[NMAX];
pii nxt[NMAX];

void add_edge(int x, int y, int cap, int cost) {
	g[x].push_back({ y, cap, cost, sz(g[y]) });
	g[y].push_back({ x, 0, -cost, sz(g[x]) - 1 });
}

void read() {
	fin >> n >> m >> source >> sink;
	for (int i = 1, x, y, c, w; i <= m; i++) {
		fin >> x >> y >> c >> w;
		add_edge(x, y, c, w);
	}
}

void bellman() {
	queue<int> qe;

	for (int i = 1; i <= n; i++)
		pi[i] = INF;

	qe.push(source);
	pi[source] = 0;

	while (!qe.empty()) {
		int u = qe.front();

		qe.pop();
		inq[u] = false;

		for (auto &it : g[u]) {
			if (it.cap && ckmin(pi[it.dest], pi[u] + it.cost)) {
				if (!inq[it.dest]) {
					qe.push(it.dest);
					inq[it.dest] = true;
				}
			}
		}
	}
}

void dijkstra() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		vis[i] = false;
		pi2[i] = pi[i];
	}

	priority_queue<pii> pq;

	pq.push({0, source});
	dist[source] = pi[source] = 0;
	nxt[source] = {0, 0};

	while (!pq.empty()) {
		int d = pq.top().fi;
		int u = pq.top().se;

		pq.pop();

		if (vis[u]) continue;
		vis[u] = true;

		int i = -1;
		for (auto &it : g[u]) {
			i++;
			if (it.cap && ckmin(dist[it.dest], dist[u] + it.cost + pi2[u] - pi2[it.dest])) {
				pi[it.dest] = pi[u] + it.cost;
				nxt[it.dest] = { u, i };
				pq.push({-dist[it.dest], it.dest});
			}
		}
	}
}

int fmcm() {
	int min_cost = 0;
	bellman();
	while (dijkstra(), dist[sink] != INF) {
		int flow = INF, cost = 0;
		for (int u = sink; u != source; u = nxt[u].fi) {
			Edge &e = g[nxt[u].fi][nxt[u].se];
			cost += e.cost;
			ckmin(flow, e.cap);
		}
		for (int u = sink; u != source; u = nxt[u].fi) {
			Edge &e = g[nxt[u].fi][nxt[u].se];
			e.cap -= flow;
			g[u][e.other].cap += flow;
		}
		min_cost += flow * cost;
	}
	return min_cost;
}

signed main() {
	read();
	fout << fmcm() << endl;
	return 0;
}
