#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NMAX = 351;
const int inf = (int)1e9 * 2;
struct edge{
    int x,y,c;
};
int N,M,sursa,destinatie,capacitate[NMAX][NMAX],flow[NMAX][NMAX],ans,p[NMAX],cost[NMAX],from[NMAX],m[NMAX][NMAX];
vector<edge>edges;
vector<pair<int,int>>ad[NMAX];

bool djaikstra() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    cost[sursa] = 0;
    pq.push({0,sursa});
    while (pq.size()) {
        auto a = pq.top();
        pq.pop();
        if (cost[a.second] < a.first) continue;
        for (auto& v : ad[a.second])
            if (v.second - p[v.first] + p[a.second] + cost[a.second] < cost[v.first] && capacitate[a.second][v.first] - flow[a.second][v.first] > 0) {
                cost[v.first] = v.second - p[v.first] + p[a.second] + cost[a.second];
                from[v.first] = a.second;
                pq.push({cost[v.first],v.first});
            }
    }
    if (cost[destinatie] == inf)
        return false;
    for (int i = 1; i <= N;++i) {
        p[i] = cost[i] + p[i] - p[sursa];
        cost[i] = inf;
        }
    return true;
}

void refa_drum() {
    int node = destinatie;
    int mx_flow = (int)1e9;
    while (node != sursa) {
        mx_flow = min(mx_flow,capacitate[from[node]][node] - flow[from[node]][node]);
        node = from[node];
    }

    node = destinatie;
    while (node != sursa) {
        flow[from[node]][node] += mx_flow;
        flow[node][from[node]] -= mx_flow;
        ans += mx_flow * m[from[node]][node];
        node = from[node];
    }
}

main(){
    freopen("fmcm.in","r",stdin);
    freopen("fmcm.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> sursa >> destinatie;
    for (int i = 1; i <= N;++i)
        p[i] = cost[i] = inf;
    p[sursa] = 0;
    while (M--) {
        int u,v,f,c; cin >> u >> v >> f >> c;
        ad[u].push_back({v,c});
        ad[v].push_back({u,-c});
        capacitate[u][v] += f;
        edges.push_back({u,v,c});
        m[u][v] = c;
        m[v][u] = -c;
    }
    for (int i = 1; i < N;++i)
        for (auto &e : edges)
            if (p[e.x] != inf)
                p[e.y] = min(p[e.y],p[e.x] + e.c);
    for (auto e : edges)
        if (e.c + p[e.x] - p[e.y] < 0) {
            cout << "RAU";
        }
    while(djaikstra()) {
        refa_drum();
    }
    cout << ans;
    return 0;
}
