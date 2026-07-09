#include <bits/stdc++.h>
#define int long long
using namespace std;

int cap[355][355], cost[355][355], par[355], ans;
int inq[355], dist[355], d_norm[355], distreal[355];
vector<int> adj[355];

void bellman(int n, int s) {
    queue<int> q;
    q.push(s);
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e15;
        inq[i] = 0;
        par[i] = 0;
    }
    inq[s] = 1;
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int v : adj[u]) {
            if (cap[u][v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

bool dijkstra(int n, int s, int d) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++) {
        d_norm[i] = 1e15;
        par[i] = 0;
        distreal[i] = 1e15;
    }
    d_norm[s] = distreal[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [here, u] = pq.top();
        pq.pop();
        if (here != d_norm[u]) continue;
        for (int v : adj[u]) {
            int muchie = dist[u] - dist[v] + cost[u][v];
            if (cap[u][v] && d_norm[u] + muchie < d_norm[v]) {
                d_norm[v] = d_norm[u] + muchie;
                distreal[v] = distreal[u] + cost[u][v];
                par[v] = u;
                pq.push({d_norm[v], v});
            }
        }
    }
    if (d_norm[d] == 1e15) return false;
    //acum pushez
    int curr = d, f = 1e15, sumcost = 0;
    while (curr != s) {
        f = min(f, cap[par[curr]][curr]);
        sumcost += cost[par[curr]][curr];
        curr = par[curr];
    }
    ans += f * sumcost;
    curr = d;
    while (curr != s) {
        cap[par[curr]][curr] -= f;
        cap[curr][par[curr]] += f;
        curr = par[curr];
    }
    for (int i = 1; i <= n; i++)
        dist[i] = distreal[i];
    return true;
}

signed main() {

    ifstream cin("fmcm.in");
    ofstream cout("fmcm.out");

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 1; i <= m; i++) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = c;
        cost[u][v] = w;
        cost[v][u] = -w;
    }
    bellman(n, s);
    while(dijkstra(n, s, d)) { }
    cout << ans << '\n';
    return 0;
}