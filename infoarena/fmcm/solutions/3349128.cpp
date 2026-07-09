#include <bits/stdc++.h>
#define int long long
using namespace std;

int cap[355][355], cost[355][355], par[355];
int inq[355], dist[355];
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
        for (int v : adj[u]) {
            if (cap[u][v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                par[v] = u;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
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
    int ans = 0;
    bellman(n, s);
    while (dist[d] != 1e15) {
        //bagam flux
        int f = 1e9, curr = d, sumcost = 0;
        while (curr != s) {
            f = min(f, cap[par[curr]][curr]);
            sumcost += cost[par[curr]][curr];
            curr = par[curr];
        }
        curr = d;
        ans += f * sumcost;
        while (curr != s) {
            cap[par[curr]][curr] -= f;
            cap[curr][par[curr]] += f;
            curr = par[curr];
        }
        bellman(n, s);
    }
    cout << ans << '\n';
    return 0;
}