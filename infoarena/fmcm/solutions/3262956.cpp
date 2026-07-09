#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Dinic {
    int n;
    const int inf = 1e9;
    struct Edge {
        int from, to, cost, cap, rev;
    };
    vector<vector<int>> adj; // Adjacency list
    vector<Edge> edge;       // Edge list
    vector<int> dist, h, vine;

    Dinic(int N) : n(N + 5), adj(N + 5), dist(N + 5), h(N + 5, 0), vine(N + 5, -1) {}

    void baga(int from, int to, int cap, int cost) {
        edge.push_back({from, to, cost, cap, (int)adj[to].size()});
        adj[from].push_back(edge.size() - 1);
        edge.push_back({to, from, -cost, 0, (int)adj[from].size() - 1});
        adj[to].push_back(edge.size() - 1);
    }

    bool bellman(int s, int d) {
        fill(dist.begin(), dist.end(), inf);
        dist[s] = 0;
        for (int i = 0; i < n; i++) {
            bool updated = false;
            for (int u = 0; u < n; u++) {
                for (int id : adj[u]) {
                    auto& e = edge[id];
                    if (e.cap > 0 && dist[u] + e.cost < dist[e.to]) {
                        dist[e.to] = dist[u] + e.cost;
                        vine[e.to] = id;
                        updated = true;
                    }
                }
            }
            if (!updated) break;
        }
        h = dist;
        return h[d] != inf;
    }

    bool dijkstra(int s, int d) {
        fill(dist.begin(), dist.end(), inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, s});
        dist[s] = 0;
        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (cost > dist[u]) continue;
            for (int id : adj[u]) {
                auto& e = edge[id];
                int reduced_cost = e.cost + h[u] - h[e.to];
                if (e.cap > 0 && dist[u] + reduced_cost < dist[e.to]) {
                    dist[e.to] = dist[u] + reduced_cost;
                    vine[e.to] = id;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        for (int i = 0; i < n; i++) if (dist[i] < inf) h[i] += dist[i];
        return dist[d] != inf;
    }

    pair<int, int> push(int s, int d) {
        int flow = inf, cost = 0;
        for (int x = d; x != s; x = edge[vine[x]].from) {
            flow = min(flow, edge[vine[x]].cap);
        }
        for (int x = d; x != s; x = edge[vine[x]].from) {
            edge[vine[x]].cap -= flow;
            edge[vine[x] ^ 1].cap += flow;
            cost += edge[vine[x]].cost * flow;
        }
        return {flow, cost};
    }

    pair<int, int> fmcm(int s, int d) {
        int flux = 0, cost = 0;
        if (!bellman(s, d)) return {0, 0};
        while (dijkstra(s, d)) {
            auto [f, c] = push(s, d);
            flux += f;
            cost += c;
        }
        return {flux, cost};
    }
};

int main() {
    ifstream cin("fmcm.in");
    ofstream cout("fmcm.out");

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    Dinic g(n);
    for (int i = 0; i < m; i++) {
        int u, v, cap, cost;
        cin >> u >> v >> cap >> cost;
        g.baga(u, v, cap, cost);
    }
    cout << g.fmcm(s, d).second << '\n';

    return 0;
}
