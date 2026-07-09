#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream fin("fmcm.in");
ofstream fout("fmcm.out");

const int MAXN = 355;
const int INF = 1e9;

struct Edge {
    int v, cap, cost, rev;
    Edge(int _v, int _cap, int _cost, int _rev) : v(_v), cap(_cap), cost(_cost), rev(_rev) {}
};

vector<Edge> G[MAXN];
int dist[MAXN], phi[MAXN], parent[MAXN], parent_edge[MAXN];
bool in_queue[MAXN];

void add_edge(int u, int v, int cap, int cost) {
    G[u].push_back(Edge(v, cap, cost, G[v].size()));
    G[v].push_back(Edge(u, 0, -cost, G[u].size() - 1));
}

bool bellman_ford(int s, int t, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        in_queue[i] = false;
    }
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    in_queue[s] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        in_queue[u] = false;
        for (int i = 0; i < G[u].size(); i++) {
            Edge &e = G[u][i];
            if (e.cap > 0 && dist[u] + e.cost < dist[e.v]) {
                dist[e.v] = dist[u] + e.cost;
                parent[e.v] = u;
                parent_edge[e.v] = i;
                if (!in_queue[e.v]) {
                    q.push(e.v);
                    in_queue[e.v] = true;
                }
            }
        }
    }
    return dist[t] != INF;
}

void dijkstra(int s, int n) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if (d != dist[u]) continue;
        for (int i = 0; i < G[u].size(); i++) {
            Edge &e = G[u][i];
            int nd = dist[u] + e.cost + phi[u] - phi[e.v];
            if (e.cap > 0 && nd < dist[e.v]) {
                dist[e.v] = nd;
                parent[e.v] = u;
                parent_edge[e.v] = i;
                pq.push({nd, e.v});
            }
        }
    }
}

int main() {
    int N, M, S, D;
    fin >> N >> M >> S >> D;

    for (int i = 0; i < M; i++) {
        int x, y, c, z;
        fin >> x >> y >> c >> z;
        add_edge(x, y, c, z);
    }

    for (int i = 1; i <= N; i++) phi[i] = 0;

    if (bellman_ford(S, D, N)) {
        for (int i = 1; i <= N; i++) {
            phi[i] = (dist[i] == INF ? 0 : dist[i]);
        }
    }

    int total_flow = 0, total_cost = 0;

    while (true) {
        dijkstra(S, N);
        if (dist[D] == INF) break;

        for (int i = 1; i <= N; i++) {
            if (dist[i] != INF) phi[i] += dist[i];
        }

        int flow = INF;
        for (int u = D; u != S; u = parent[u]) {
            int p = parent[u];
            Edge &e = G[p][parent_edge[u]];
            flow = min(flow, e.cap);
        }

        for (int u = D; u != S; u = parent[u]) {
            int p = parent[u];
            Edge &e = G[p][parent_edge[u]];
            e.cap -= flow;
            G[e.v][e.rev].cap += flow;
            total_cost += flow * e.cost;
        }
        total_flow += flow;
    }

    fout << total_cost << '\n';
    return 0;
}