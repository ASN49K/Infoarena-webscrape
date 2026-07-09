#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORR(i, a, b) for (int i = a; i >= b; --i)

const int N = 1e3 + 9, Inf = 0x3f3f3f3f;
const bool test_case = false;

int n, m, s, d;
vvi G(N);

struct edge {
    int from, to, cap, flow, cost;
    edge(int from, int to, int cap, int flow, int cost)
        : from(from), to(to), cap(cap), flow(flow), cost(cost) {}
};
vector<edge> edges;

void add_edge(int x, int y, int c, int z) {
    G[x].pb(edges.size());
    edges.pb({x, y, c, 0, z});
    G[y].pb(edges.size());
    edges.pb({y, x, 0, 0, -z});
}

int dist[N];
bool inQ[N];

void BellmanFord() {
    queue<int> q;
    FOR(i, 1, n) dist[i] = Inf;
    dist[s] = 0;
    q.push(s);
    inQ[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        inQ[x] = false;

        for (auto i : G[x]) {
            if (i % 2 == 0) continue;
            auto& e = edges[i];
            if (dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (!inQ[e.to]) {
                    q.push(e.to);
                    inQ[e.to] = true;
                }
            }
        }
    }
}

int dd[N], t[N];

bool Dijkstra() {
    priority_queue<pii, vector<pii>, greater<>> q;
    FOR(i, 1, n) dd[i] = Inf;
    dd[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto [dx, x] = q.top();
        q.pop();
        if (dx > dd[x]) continue;

        for (auto i : G[x]) {
            auto& e = edges[i];
            if (e.flow < e.cap && dd[e.to] > dd[e.from] + dist[e.from] + e.cost - dist[e.to]) {
                t[e.to] = i;
                dd[e.to] = dd[e.from] + dist[e.from] + e.cost - dist[e.to];
                q.push({dd[e.to], e.to});
            }
        }
    }
    return dd[d] != Inf;
}

int FMCM() {
    int ret = 0;
    while (Dijkstra()) {
        int flow = INT_MAX;
        for (int x = d; x != s; x = edges[t[x]].from)
            flow = min(flow, edges[t[x]].cap - edges[t[x]].flow);

        ret += flow * (dd[d] + dist[d]);

        for (int x = d; x != s; x = edges[t[x]].from) {
            edges[t[x]].flow += flow;
            edges[t[x] ^ 1].flow -= flow;
        }
    }
    return ret;
}

void solve() {
    scanf("%d %d %d %d", &n, &m, &s, &d);
    int x, y, c, z;
    FOR(i, 1, m) {
        scanf("%d %d %d %d", &x, &y, &c, &z);
        add_edge(x, y, c, z);
    }
    BellmanFord();
    printf("%d\n", FMCM());
}

int main() {
    freopen("fmcm.in", "r", stdin);
    freopen("fmcm.out", "w", stdout);

    int t = 1;
    if (test_case) scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
