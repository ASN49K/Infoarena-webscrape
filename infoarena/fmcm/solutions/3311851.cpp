#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

struct Dinic {
	int n;
	struct Edge {
		int from, to, cap, cost, prec;
	};
	vector<Edge> edge;
	vector<int> prec, h, vine;
	Dinic(int N) {
		n = N;
		prec.resize(n, -1);
		vine.resize(n);
		h.resize(n);
	}
	void baga(int from, int to, int cap, int cost) {
		edge.push_back({from, to, cap, cost, prec[from]});
		prec[from] = edge.size() - 1;
		edge.push_back({to, from, 0, -cost, prec[to]});
		prec[to] = edge.size() - 1;
	}
	bool bellman(int s, int d) {
		h.assign(n, inf);
		h[s] = 0;
		while(1) {
			bool steag = 0;
			for (int i = 0; i < (int)edge.size(); i ++) {
				if (edge[i].cap > 0 && h[edge[i].from] != inf && h[edge[i].from] + edge[i].cost < h[edge[i].to]) {
					h[edge[i].to] = h[edge[i].from] + edge[i].cost;
					vine[edge[i].to] = i;
					steag = 1;
				}
			}
			if (!steag)
				break;
		}
		return h[d] != inf;
	}
	bool dijkstra(int s, int d) {
		priority_queue<pair<int, int>> pq;
		pq.push({0, s});
		vector<int> dist(n, inf), real(n, inf);
		vector<bool> f(n, 0);
		dist[s] = 0;
		real[s] = 0;
		vine[s] = -1;
		while(!pq.empty()) {
			int g = pq.top().second;
			pq.pop();
			if(f[g])
				continue;
			f[g] = true;
			for (int i = prec[g]; i != -1; i = edge[i].prec) {
				if (edge[i].cap > 0 && dist[edge[i].to] > h[g] - h[edge[i].to] + dist[g] + edge[i].cost) {
					dist[edge[i].to] = h[g] - h[edge[i].to] + dist[g] + edge[i].cost;
					real[edge[i].to] = real[g] + edge[i].cost;
					vine[edge[i].to] = i;
					pq.push({-dist[edge[i].to], edge[i].to});
				}
			}
		}
		h = real;
		return real[d] != inf;
	}
	pair<int, int> push(int s, int d) {
		int x = d, minn = inf, ans = 0;
		while (x != s) {
			minn = min(minn, edge[vine[x]].cap);
			x = edge[vine[x]].from;
		}
		x = d;
		while(x != s) {
			ans += minn * edge[vine[x]].cost;
			edge[vine[x]].cap -= minn;
			edge[vine[x] ^ 1].cap += minn;
			x = edge[vine[x]].from;
		}
		return {minn, ans};
	}
	pair<int, int> fmcm(int s, int d)
	{
		int flux = 0, cost = 0;
		if(!bellman(s, d))
			return {0, 0};
		while (dijkstra(s, d)) {
			pair<int, int> x = push(s, d);
			flux += x.first;
			cost += x.second;
		}
		return {flux, cost};
	}
};

int main() {
	ifstream cin("fmcm.in");
	ofstream cout("fmcm.out");
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	Dinic g(n + 1);
	for(int i = 0; i < m; i ++) {
		int x, y, c, z;
		cin >> x >> y >> c >> z;
		g.baga(x, y, c, z);
	}
	cout << g.fmcm(s, d).second;
}
