#include <bits/stdc++.h>

std::ifstream fin("fmcm.in");
std::ofstream fout("fmcm.out");

const int MAX_N = 350;
const int INF = 1e9;

struct edge {
    int to, cap, flow, cost, rid;
};

struct MaxFlow {
    std::vector<edge> g[MAX_N + 1];
    bool vis[MAX_N + 1];
    int potential[MAX_N + 1];
    int dist[MAX_N + 1];
    int flow_here[MAX_N + 1];
    int ptr[MAX_N + 1];
    bool in_queue[MAX_N + 1];
    int n;


    void add_edge(int from, int to, int cap, int cost) {
        g[from].push_back(edge {to, cap, 0, cost, g[to].size()});
        g[to].push_back(edge {from, 0, 0, -cost, g[from].size() - 1});
    }

    void bellman(int s) {
        std::queue<int> q;
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
            in_queue[i] = false;
        }

        q.push(s);
        dist[s] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            in_queue[node] = false;

            for (const auto & edg : g[node]) {
                if (edg.flow < edg.cap && dist[node] + edg.cost < dist[edg.to]) {
                    dist[edg.to] = dist[node] + edg.cost;
                    if (!in_queue[edg.to]) {
                        in_queue[edg.to] = true;
                        q.push(edg.to);
                    }
                }
            }
        }
    }

    bool dijkstra(int s, int t) {
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
            dist[i] = INF;
            flow_here[i] = 0;
        }


        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, s));
        dist[s] = 0;
        flow_here[s] = INF;

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = true;

            for (const auto & edg : g[node]) {
                if (edg.flow < edg.cap && dist[node] + edg.cost + potential[node] - potential[edg.to] < dist[edg.to]) {
                    dist[edg.to] = dist[node] + edg.cost + potential[node] - potential[edg.to];
                    flow_here[edg.to] = std::min(flow_here[node], edg.cap - edg.flow);
                    pq.push(std::make_pair(dist[edg.to], edg.to));
                    ptr[edg.to] = edg.rid;
                }
            }
        }

        return vis[t];
    }

    int max_flow(int s, int t) {
        bellman(s);

        for (int i = 1; i <= n; i++)
            potential[i] = dist[i];

        int total_cost = 0;

        while (dijkstra(s, t)) {
            for (int i = 1; i <= n; i++)
                dist[i] += potential[i] - potential[s];
            for (int i = 1; i <= n; i++)
                potential[i] = dist[i];

            int flow = flow_here[t];
            int node = t;

            while (node != s) {
                auto & edg = g[node][ptr[node]];
                edg.flow -= flow;
                g[edg.to][edg.rid].flow += flow;
                node = edg.to;
            }

            total_cost += flow * dist[t];
        }

        return total_cost;
    }

    MaxFlow(int n) : n(n) {}
};

int n, m, s, d;

void solve() {
    fin >> n >> m >> s >> d;

    MaxFlow flow(n);

    for (int i = 1; i <= m; i++) {
        int u, v, c, z;
        fin >> u >> v >> c >> z;
        flow.add_edge(u, v, c, z);
    }

    fout << flow.max_flow(s, d) << '\n';
}

int main() {
    solve();
    return 0;
}
