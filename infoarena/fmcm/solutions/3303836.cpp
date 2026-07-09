#include <fstream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

struct Edge {
    int to;
    ll cap, cost;
    int rev;
};

struct MinCostMaxFlow {
    int N;
    vector<vector<Edge>> G;
    vector<ll> h, dist;
    vector<int> prevv, preve;

    MinCostMaxFlow(int n)
      : N(n)
      , G(n)
      , h(n, 0)
      , dist(n)
      , prevv(n)
      , preve(n)
    {}

    void addEdge(int u, int v, ll cap, ll cost) {
        G[u].push_back({v, cap, cost, (int)G[v].size()});
        G[v].push_back({u, 0, -cost, (int)G[u].size()-1});
    }

    pair<ll, ll> minCostMaxFlow(int s, int t) {
        ll flow = 0, cost = 0;
        // inițializare potențiale (Bellman–Ford)
        fill(h.begin(), h.end(), INF);
        h[s] = 0;
        bool updated = true;
        for(int iter = 0; iter < N && updated; ++iter) {
            updated = false;
            for(int u = 0; u < N; ++u) {
                if(h[u] == INF) continue;
                for(auto &e : G[u]) {
                    if(e.cap > 0 && h[e.to] > h[u] + e.cost) {
                        h[e.to] = h[u] + e.cost;
                        updated = true;
                    }
                }
            }
        }
        // drumuri succesive cu Dijkstra
        while (true) {
            priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pq.push({0, s});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (dist[u] < d) continue;
                for (int i = 0; i < (int)G[u].size(); ++i) {
                    auto &e = G[u][i];
                    if (e.cap > 0) {
                        ll nd = dist[u] + e.cost + h[u] - h[e.to];
                        if (dist[e.to] > nd) {
                            dist[e.to] = nd;
                            prevv[e.to] = u;
                            preve[e.to] = i;
                            pq.push({nd, e.to});
                        }
                    }
                }
            }
            if (dist[t] == INF) break;
            for (int v = 0; v < N; ++v)
                if (dist[v] < INF) h[v] += dist[v];
            ll dflow = INF;
            for (int v = t; v != s; v = prevv[v])
                dflow = min(dflow, G[prevv[v]][preve[v]].cap);
            flow += dflow;
            cost += dflow * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                auto &e = G[prevv[v]][preve[v]];
                e.cap -= dflow;
                G[v][e.rev].cap += dflow;
            }
        }
        return {flow, cost};
    }
};

int main(){
    ifstream fin("fmcm.in");
    ofstream fout("fmcm.out");
    if (!fin || !fout) return 0;

    int n, m, s, t;
    fin >> n >> m >> s >> t;

    MinCostMaxFlow mf(n + 1);
    for(int i = 0; i < m; ++i) {
        int x, y;
        ll z, c;
        fin >> x >> y >> z >> c;
        mf.addEdge(x, y, z, c);
    }

    auto [maxFlow, minCost] = mf.minCostMaxFlow(s, t);
    fout << minCost << "\n";
    return 0;
}
