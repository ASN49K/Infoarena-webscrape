#include <bits/stdc++.h>
using namespace std;

const int kInf = 1e9;

template<class T>
bool ckmin(T &x, const T &y) {
	return y < x ? x = y, true : false;
}

struct edge_t {
	int to, cap, cst;
	edge_t() {}
	edge_t(int to, int cap, int cst) : to(to), cap(cap), cst(cst) {}
};

struct node_t {
	int u, d;
	node_t() {}
	node_t(int u, int d) : u(u), d(d) {}
	bool operator < (const node_t &oth) const {
		return d > oth.d;
	}
};

struct mcmf {
	int n;
	vector<vector<int>> adj;
	vector<edge_t> edges;
	vector<int> dist, real_dist, help_dist, par;
	priority_queue<node_t> pq;
	mcmf() {}
	mcmf(int n) : n(n), adj(n), dist(n), real_dist(n), help_dist(n), par(n) {}
	void add_edge(int u, int v, int cap, int cst) {
		int m = edges.size();
		edges.emplace_back(v, cap, cst);
		edges.emplace_back(u, 0, -cst);
		adj[u].emplace_back(m);
		adj[v].emplace_back(m + 1);
	}
	void init_dist(int s) {
		queue<int> q;
		vector<bool> inq(n);
		fill(real_dist.begin(), real_dist.end(), kInf);
		real_dist[s] = 0;
		q.emplace(s);
		inq[s] = true;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			inq[u] = false;
			for(const auto &it : adj[u]) {
				auto [to, cap, cst] = edges[it];
				if(!cap) {
					continue;
				}
				if(real_dist[u] + cst < real_dist[to]) {
					real_dist[to] = real_dist[u] + cst;
					if(!inq[to]) {
						q.emplace(to);
						inq[to] = true;
					}
				}
			}
		}
	}
	bool dij(int s, int d) {
		dist = real_dist;
		fill(real_dist.begin(), real_dist.end(), kInf);
		fill(help_dist.begin(), help_dist.end(), kInf);
		real_dist[s] = 0;
		help_dist[s] = 0;
		pq.emplace(s, help_dist[s]);
		while(!pq.empty()) {
			auto [u, d] = pq.top();
			pq.pop();
			if(d != help_dist[u]) {
				continue;
			}
			for(const auto &it : adj[u]) {
				auto [to, cap, cst] = edges[it];
				if(!cap) {
					continue;
				}
				if(help_dist[u] + dist[u] + cst < help_dist[to] + dist[to]) {
					par[to] = it;
					help_dist[to] = help_dist[u] + dist[u] + cst - dist[to];
					real_dist[to] = real_dist[u] + cst;
					pq.emplace(to, help_dist[to]);
				}
			}
		}
		return help_dist[d] != kInf;
	}
	int mincost(int s, int d) {
		int res = 0;
		while(dij(s, d)) {
			int flow = kInf, cost = 0;
			for(int u = d; u != s; u = edges[par[u] ^ 1].to) {
				ckmin(flow, edges[par[u]].cap);
				cost += edges[par[u]].cst;
			}
			res += cost * flow;
			for(int u = d; u != s; u = edges[par[u] ^ 1].to) {
				edges[par[u]].cap -= flow;
				edges[par[u] ^ 1].cap += flow;
			}
		}
		return res;
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
#ifdef INFOARENA
	freopen("fmcm.in", "r", stdin);
	freopen("fmcm.out", "w", stdout);
#endif
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	s--; d--;
	mcmf graph(n);
	for(int i = 0; i < m; i++) {
		int u, v, cap, cst;
		cin >> u >> v >> cap >> cst;
		u--; v--;
		graph.add_edge(u, v, cap, cst);
	}
	graph.init_dist(s);
	cout << graph.mincost(s, d);
	return 0;
}