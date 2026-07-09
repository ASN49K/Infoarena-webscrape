#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using PA = pair<int, int>;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

int n, m, S, D;
int cap[355][355], cost[355][355];
int d[355], h[355], p[355];
vector<int> G[355];
priority_queue<PA, vector<PA>, greater<PA>> Q;

bool dijkstra() {
    fill(d, d + n + 1, INF);
    fill(p, p + n + 1, 0);
    
    d[S] = 0;
    Q.push({0, S});

    while (!Q.empty()) {
        int dist = Q.top().first;
        int u = Q.top().second;
        Q.pop();

        if (dist > d[u]) continue;

        for (int v : G[u]) {
            if (cap[u][v] > 0) {
                int w = cost[u][v] + h[u] - h[v];
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    p[v] = u;
                    Q.push({d[v], v});
                }
            }
        }
    }
    return d[D] != INF;
}

int main() {
    fin >> n >> m >> S >> D;
    for (int i = 1; i <= m; ++i) {
        int u, v, c, z;
        fin >> u >> v >> c >> z;
        G[u].push_back(v);
        G[v].push_back(u);
        cap[u][v] = c;
        cost[u][v] = z;
        cost[v][u] = -z;
    }
    fin.close();

    int maxFlow = 0;
    long long minCost = 0;

    while (dijkstra()) {
        for (int i = 1; i <= n; ++i) {
            if (d[i] != INF) {
                h[i] += d[i];
            }
        }

        int flow = INF;
        for (int v = D; v != S; v = p[v]) {
            int u = p[v];
            flow = min(flow, cap[u][v]);
        }

        for (int v = D; v != S; v = p[v]) {
            int u = p[v];
            cap[u][v] -= flow;
            cap[v][u] += flow;
            minCost += (long long)flow * cost[u][v];
        }
        maxFlow += flow;
    }

    fout << minCost << "\n";
    return 0;
}