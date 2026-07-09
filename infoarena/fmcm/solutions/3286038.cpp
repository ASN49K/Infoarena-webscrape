#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
#include <climits>
//#include <iostream>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
const string TASK("fmcm");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 500 + 9, Inf = 0x3f3f3f3f;
const bool test_case = false;

int n, m, s, d;
vvi G(N);

struct edge
{
    int from, to, cap, flow, cost;
    edge(int from, int to, int cap, int flow, int cost) : from(from), to(to), cap(cap), flow(flow), cost(cost)
    {}
};
vector<edge> edges;

inline void add_edge(int x, int y, int c, int z)
{
    G[x].pb(edges.size());
    edges.pb({x, y, c, 0, z});
    G[y].pb(edges.size());
    edges.pb({y, x, 0, 0, -z});
}

int dist[N];
bool inQ[N];
inline void BellmanFord()
{
    queue<int> q;
    FOR(i, 1, n)dist[i] = Inf;
    dist[s] = 0;
    q.push(s);
    inQ[s] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        inQ[x] = false;

        for(auto i : G[x])
        {
            if(i % 2 == 0)continue;
            auto& e = edges[i];
            if(dist[e.to] > dist[e.from] + e.cost)
            {
                dist[e.to] = dist[e.from] + e.cost;
                if(!inQ[e.to])
                {
                    q.push(e.to);
                    inQ[e.to] = true;
                }
            }
        }
    }
}

int dd[N], t[N], dep[N];
inline bool Dijkstra()
{
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<>> q;
    FOR(i, 1, n)dd[i] = Inf;
    dd[s] = 0;
    q.push({{0, 0}, s});

    while(!q.empty())
    {
        auto dx = q.top().ff.ff, dp = q.top().ff.ss, x = q.top().ss;
        q.pop();

        if(dx > dd[x])continue;
        if(x == d)break;

        for(auto i : G[x])
        {
            auto& e = edges[i];
            if(e.flow < e.cap && dd[e.to] > dd[e.from] + dist[e.from] + e.cost - dist[e.to])
            {
                t[e.to] = i;
                dd[e.to] = dd[e.from] + dist[e.from] + e.cost - dist[e.to];
                dep[e.to] = dep[e.from] + 1;
                q.push({{dd[e.to], dep[e.to]}, e.to});
            }
        }
    }

    return dd[d] != Inf;
}

inline int FMCM()
{
    int ret = 0;
    for(; Dijkstra();)
    {
        int flow = INT_MAX;
        for(int x = d; x != s; x = edges[t[x]].from)
            flow = min(flow, edges[t[x]].cap - edges[t[x]].flow);

        ret += flow * (dd[d] + dist[d]);

        for(int x = d; x != s; x = edges[t[x]].from)
        {
            edges[t[x]].flow += flow;
            edges[t[x] ^ 1].flow -= flow;
        }
    }
    return ret;
}

void solve()
{
    cin >> n >> m >> s >> d;

    int x, y, c, z;
    FOR(i, 1, m)
    {
        cin >> x >> y >> c >> z;
        add_edge(x, y, c, z);
    }

    BellmanFord();
    cout << FMCM() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    if(test_case)cin >> t;
    while(t --)
        solve();
    return 0;
}
