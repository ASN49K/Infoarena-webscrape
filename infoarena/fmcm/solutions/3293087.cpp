#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

std::ifstream fin("fmcm.in");
std::ofstream fout("fmcm.out");

const int MAX_N = 350;
const int INF = 1e9;

struct Flow {
    int n;
    bool in_queue[MAX_N + 1];
    int dist[MAX_N + 1];
    int potential[MAX_N + 1];
    bool vis[MAX_N + 1];


    struct edge {
        int to, rid, c, f, z;
    };

    int who[MAX_N + 1];
    int max_flow[MAX_N + 1];

    std::vector<edge> g[MAX_N + 1];

    void add_edge(int x, int y, int c, int z) {
        int szx = g[x].size(), szy = g[y].size();
        g[x].push_back(edge {y, szy, c, 0, z});
        g[y].push_back(edge {x, szx, 0, 0, -z});
    }

    Flow(int _n) : n(_n) {}

    void bellman(int s) {
        for (int i = 1; i <= n; i++)
            dist[i] = INF;

        std::queue<int> q;
        q.push(s);
        in_queue[s] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            in_queue[node] = false;
            for (auto &it : g[node])
                if (!in_queue[it.to] && it.f < it.c && dist[node] + it.z < dist[it.to]) {
                    dist[it.to] = dist[node] + it.z;
                    in_queue[it.to] = false;
                    q.push(it.to);
                }
        }
    }

    bool dijkstra(int s, int t) {
        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
            vis[i] = false;
        }

        std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, s));
        dist[s] = 0;
        max_flow[s] = INF;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (vis[node])
                continue;
            vis[node] = true;
            for (auto &it : g[node])
                if (it.f < it.c && dist[node] + it.z + potential[node] - potential[it.to] < dist[it.to]) {
                    dist[it.to] = dist[node] + it.z + potential[node] - potential[it.to];
                    who[it.to] = it.rid;
                    max_flow[it.to] = std::min(max_flow[node], it.c - it.f);
                    pq.push(std::make_pair(dist[it.to], it.to));
                }
        }
        return vis[t];
    }

    long long flow(int s, int t) {
        bellman(s);

        for (int i = 1; i <= n; i++)
            potential[i] = dist[i];

        long long total_cost = 0;

        while (dijkstra(s, t)) {
            for (int i = 1; i <= n; i++)
                dist[i] += potential[i] - potential[s];
            for (int i = 1; i <= n; i++)
                potential[i] = dist[i];

            int aux = t;
            int flux = max_flow[t];

            while (aux != s) {
                edge& e = g[aux][who[aux]];
                e.f -= flux;
                g[e.to][e.rid].f += flux;
                total_cost -= 1LL * flux * e.z;
                aux = e.to;
            }
        }

        return total_cost;
    }
};

int n, m, s, t;

void solve() {
    fin >> n >> m >> s >> t;

    Flow my_flow(n);

    for (int i = 1; i <= m; i++) {
        int x, y, c, z;
        fin >> x >> y >> c >> z;
        my_flow.add_edge(x, y, c, z);
    }

    fout << my_flow.flow(s, t) << '\n';
}

int main() {
    solve();
    return 0;
}
