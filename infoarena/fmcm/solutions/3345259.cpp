#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Flow {
    struct Edge {
        int v, c, w;
        Edge(int _v, int _c, int _w) : v(_v), c(_c), w(_w) {}
    };

    const int INF = 999999999;
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<int> par, dist, old_dist;
    int n, s, t;

    void build(int _n) {
        n = _n;
        par.resize(n);
        dist.resize(n);
        old_dist.resize(n);
        edges.clear();
        adj.assign(n, vector<int>());
    }

    void addEdge(int u, int v, int c, int w) {
        adj[u].push_back(edges.size());
        edges.emplace_back(v, c, w);
        adj[v].push_back(edges.size());
        edges.emplace_back(u, 0, -w);
    }

    void potentials() {
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i : adj[u]) {
                const Edge &e = edges[i];
                if(e.c > 0 && dist[u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[u] + e.w;
                    q.push(e.v);
                }
            }
        }
        old_dist = dist;
    }

    bool dijkstra() {
        fill(dist.begin(), dist.end(), INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, s);
        dist[s] = 0;
        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if(w != dist[u]) {
                continue;
            }
            for(int i : adj[u]) {
                const Edge &e = edges[i];
                if(e.c > 0 && w + e.w - old_dist[e.v] + old_dist[u] < dist[e.v]) {
                    dist[e.v] = w + e.w - old_dist[e.v] + old_dist[u];
                    pq.emplace(dist[e.v], e.v);
                    par[e.v] = i;
                }
            }
        }

        for(int i=0; i<n; ++i) {
            old_dist[i] += dist[i];
        }

        return dist[t] < INF;
    }

    pair<int, int> getFlow(int _s, int _t) {
        s = _s; t = _t;
        int f = 0, w = 0;
        potentials();
        while(dijkstra()) {
            int f2 = INF, w2 = 0;
            for(int u = t; u != s; u = edges[par[u] ^ 1].v) {
                f2 = min(f2, edges[par[u]].c);
                w2 += edges[par[u]].w;
            }
            f += f2;
            w += f2 * w2;
            for(int u = t; u != s; u = edges[par[u] ^ 1].v) {
                edges[par[u]].c -= f2;
                edges[par[u] ^ 1].c += f2;
            }
        }
        return {f, w};
    }
};

void testcase() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    Flow flow;
    flow.build(n);
    while(m--) {
        int u, v, c, w; cin >> u >> v >> c >> w;
        flow.addEdge(u - 1, v - 1, c, w);
    }
    cout << flow.getFlow(s - 1, t - 1).second << '\n';
}

signed main() {
    #ifndef LOCAL
    freopen("fmcm.in", "r", stdin);
    freopen("fmcm.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Z; Z = 1;
    for(int iZ = 1; iZ <= Z; ++iZ) {
        testcase();
    }
    return 0;
}
