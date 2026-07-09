#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

std::ifstream fin("fmcm.in");
std::ofstream fout("fmcm.out");

const int MAX_N = 350;
const int INF = 1e9;

int n, m, s, d;

struct Flow {
    struct edge {
        int to, flow, cap, cost, rid;
    };

    std::vector<edge> g[MAX_N + 1];
    int dist[MAX_N + 1];
    int potential[MAX_N + 1];
    bool vis[MAX_N + 1];
    int ptr[MAX_N + 1];
    int flow_here[MAX_N + 1];

    void add_edge(int from, int to, int cap, int cost) {
        g[from].push_back({to, 0, cap, cost, g[to].size()});
        g[to].push_back({from, 0, 0, -cost, g[from].size() - 1});
    }

    bool dijkstra(int s, int t) {
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
            vis[i] = false;
        }

        using std::pair;

        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
        dist[s] = 0;
        flow_here[s] = INF;
        pq.push(std::make_pair(0, s));

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = true;

            for (auto edg : g[node]) {
                if (edg.flow < edg.cap && dist[node] + edg.cost + potential[node] - potential[edg.to] < dist[edg.to]) {
                    dist[edg.to] = dist[node] + edg.cost + potential[node] - potential[edg.to];
                    ptr[edg.to] = edg.rid;
                    flow_here[edg.to] = std::min(flow_here[node], edg.cap - edg.flow);
                    pq.push(std::make_pair(dist[edg.to], edg.to));
                }
            }
        }

        return dist[t] < INF;
    }

    void bellman(int s) {
        bool in_queue[MAX_N + 1];

        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
            in_queue[i] = false;
        }

        dist[s] = 0;
        std::queue<int> q;
        q.push(s);
        in_queue[s] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            in_queue[node] = false;

            for (auto edg : g[node]) {
                if (edg.cap > 0 && dist[node] + edg.cost < dist[edg.to]) {
                    dist[edg.to] = dist[node] + edg.cost;
                    if (!in_queue[edg.to]) {
                        q.push(edg.to);
                        in_queue[edg.to] = true;
                    }
                }
            }
        }

    }

    int flow(int s, int t) {
        bellman(s);
        for (int i = 1; i <= n; i++)
            potential[i] = dist[i];

        int total_flow = 0, total_cost = 0;

        while (dijkstra(s, t)) {

            for (int i = 1; i <= n; i++)
                dist[i] += potential[i] - potential[s];
            for (int i = 1; i <= n; i++)
                potential[i] = dist[i];

            int node = t, cur_flow = flow_here[t];
            total_flow += cur_flow;
            total_cost += dist[t] * cur_flow;

            while (node != s) {
                auto &edg = g[node][ptr[node]];
                edg.flow -= cur_flow;
                g[edg.to][edg.rid].flow += cur_flow;

                node = edg.to;
            }
        }

        return total_cost;
    }
};

Flow flow;

void solve() {
    fin >> n >> m >> s >> d;
    for (int i = 1; i <= m; i++) {
        int u, v, cap, cost;
        fin >> u >> v >> cap >> cost;
        flow.add_edge(u, v, cap, cost);
    }
    fout << flow.flow(s, d) << '\n';
}

int main() {
    solve();
    return 0;
}
