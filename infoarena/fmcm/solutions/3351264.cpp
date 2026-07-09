/// ma cred smecher
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll

const int maxN = 100005, inf = 1e9;

struct FlowGraph {
    int n, s, d;
    struct Edge {
        int nxt, flow, cap, cost;
    };
    vector <Edge> edgeList;
    vector <vector <int>> G;
    vector <int> potential, prv;

    void addEdge(int x, int y, int cap, int cost) {
        G[x].push_back(edgeList.size());
        edgeList.push_back({y, 0, cap, cost});

        G[y].push_back(edgeList.size());
        edgeList.push_back({x, 0, 0, -cost});
    }

    void bellmanFord() {
        for (int i = 0; i < n; i++) {
            potential[i] = inf;
        }
        queue <int> q;
        vector <int> inQ(n);

        q.push(s);
        potential[s] = 0;
        inQ[s] = 1;

        while (!q.empty()) {
            int nod = q.front();
            q.pop();
            inQ[nod] = 0;

            for (int idx : G[nod]) {
                auto [nxt, flux, cap, cost] = edgeList[idx];
                if (flux == cap) {
                    continue;
                }

                if (potential[nod] + cost < potential[nxt]) {
                    potential[nxt] = potential[nod] + cost;
                    if (!inQ[nxt]) {
                        q.push(nxt);
                        inQ[nxt] = 1;
                    }
                }
            }
        }
    }

    bool dijkstra() {
        vector <int> dist(n, inf);
        vector <int> newPot(n, inf);
        
        priority_queue <pair <int, int>> heap;
        heap.push({0, s});
        dist[s] = 0;
        newPot[s] = 0;

        while (!heap.empty()) {
            auto [d, nod] = heap.top();
            heap.pop();
            d = -d;
            if (dist[nod] != d) {
                continue;
            }

            for (int idx : G[nod]) {
                auto [nxt, flux, cap, cost] = edgeList[idx];
                if (flux == cap) {
                    continue;
                }

                if (dist[nod] + cost + potential[nod] - potential[nxt] < dist[nxt]) {
                    dist[nxt] = dist[nod] + cost + potential[nod] - potential[nxt];
                    newPot[nxt] = newPot[nod] + cost;
                    prv[nxt] = idx;

                    heap.push({-dist[nxt], nxt});
                }
            }
        }

        potential = newPot;

        return dist[d] != inf;
    }

    int getCost() {
        int cost = 0;
        bellmanFord();

        while (dijkstra()) {
            int flow = inf;
            for (int nod = d; nod != s; nod = edgeList[prv[nod] ^ 1].nxt) {
                flow = min(flow, edgeList[prv[nod]].cap - edgeList[prv[nod]].flow);
            }

            for (int nod = d; nod != s; nod = edgeList[prv[nod] ^ 1].nxt) {
                edgeList[prv[nod]].flow += flow;
                edgeList[prv[nod] ^ 1].flow -= flow;
            }

            cost += flow * potential[d];
        }

        return cost;
    }

    FlowGraph(int n_) : n(n_), G(n), potential(n), prv(n) {}
};

void solve() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;

    FlowGraph graph(n);
    graph.s = s - 1;
    graph.d = d - 1;

    for (int i = 0; i < m; i++) {
        int x, y, c, z;
        cin >> x >> y >> c >> z;
        x--, y--;
        graph.addEdge(x, y, c, z);
    }

    cout << graph.getCost();
}

void prec() {

}

signed main() {
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("fmcm.in", "r", stdin);
    freopen("fmcm.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    prec();

    int nrt = 1;
    // cin >> nrt;

    for (int t = 1; t <= nrt; t++) {
        solve();
    }

    return 0;
}