#include <bits/stdc++.h>
using namespace std;

const int NMAX = 355;
const int INF = 1e9;

struct Edge {
    int to,r,cap,cost;
};
vector<Edge> e[NMAX];
int state[NMAX],from[NMAX],fromEdge[NMAX],dist[NMAX],pot[NMAX];
int n,s,t;

void addEdge(int u, int v, int cap, int cost) {
    Edge a = {v, (int)e[v].size(), cap, cost};
    Edge b = {u, (int) e[u].size(), 0, -cost};
    e[u].push_back(a);
    e[v].push_back(b);
}
int minMaxFlow() {
    int cost = 0;
    for (int i = 1;i <= n;i++)
        dist[i] = INF;
    dist[s] = 0;
    bool ok = 1;
    for (int k = 0;k < n - 1 && ok;k++) {
        ok = 0;
        for (int u = 1;u <= n;u++) {
            if (dist[u] == INF)
                continue;
            for (auto &a : e[u]) {
                if (a.cap > 0 && dist[a.to] > dist[u] + a.cost) {
                    dist[a.to] = dist[u] + a.cost;
                    ok = 1;
                }
            }
        }
    }
    for (int i = 1;i <= n;i++)
        if (dist[i] < INF)
            pot[i] = dist[i];
    while(1) {
        fill(dist, dist + n + 1, INF);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector <pair<int, int> >, greater<> > pq;
        pq.push({0, s});
        while (!pq.empty()) { 
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
                continue;
            for (int i = 0;i < (int)e[u].size();i++) {
                Edge &a = e[u][i];
                if (a.cap > 0) {
                    int nd = d + a.cost + pot[u] - pot[a.to];
                    if (nd < dist[a.to]) {
                        dist[a.to] = nd;
                        from[a.to] = u;
                        fromEdge[a.to] = i;
                        pq.push({nd, a.to});
                    }
                }
            }
        }
        if (dist[t] == INF)
            break;
        for (int i = 1;i <= n;i++)
            if (dist[i] < INF)
                pot[i] += dist[i];
        int addFlow = INF;
        for (int v = t;v != s;v = from[v]) {
            Edge &a = e[from[v]][fromEdge[v]];
            addFlow = min(addFlow, a.cap);
        }
        for (int v = t; v != s;v = from[v]) {
            Edge &a = e[from[v]][fromEdge[v]];
            a.cap -= addFlow;
            e[a.to][a.r].cap += addFlow;
            cost += addFlow * a.cost;
        }
    }
    return cost;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream fin("fmcm.in");
    ofstream fout("fmcm.out");
    int m,u,v,cap,cost;
    fin >> n >> m >> s >> t;
    for (int i = 0;i < m;i++) {
        fin >> u >> v >> cap >> cost;
        addEdge(u, v, cap, cost);
    }
    int minCost = minMaxFlow();
    fout << minCost << '\n'; 
    return 0;
}
