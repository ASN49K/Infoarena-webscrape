#include <bits/stdc++.h>
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define tpl tuple<int, int, int>
#define tiv tuple<int, int, vector<int>>
#define eb emplace_back
#define oo INT_MAX
#define OO LLONG_MAX / 2
using namespace std;

const string fn("fmcm");

ifstream in(fn + ".in");
ofstream out(fn + ".out");

#define cin in
#define cout out

const int MAX = 355;

int n, m, src, dst, cnt;
int niv[MAX + 5], from[MAX + 5], dp[MAX + 5];
int cap[MAX + 5][MAX + 5], cost[MAX + 5][MAX + 5];
vector<int> g[MAX + 5];

bool bfs(int src, int dst)
{
    memset(niv, 0, sizeof(niv));
    queue<int> que;

    que.emplace(src);
    niv[src] = 1;

    while (!que.empty())
    {
        int node = que.front();

        que.pop();

        for (auto x : g[node])
            if (cap[node][x] >0 and niv[x] == 0)
            {
                niv[x] = niv[node] + 1;
                que.emplace(x);
            }
    }

    return niv[dst] != 0;
}

int dijkstra(int src, int dst)
{
    memset(from, 0, sizeof(from));
    fill(dp, dp + MAX + 2, OO);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int lamda = 1e12;

    pq.emplace(0, src);
    dp[src] = 0;

    while (!pq.empty())
    {
        int w, node;
        tie(w, node) = pq.top();

        pq.pop();

        for (auto x : g[node])
            if (niv[x] == niv[node] + 1 and dp[x] > dp[node] + (cost[node][x] + lamda) and cap[node][x] > 0)
            {
                dp[x] = dp[node] + (cost[node][x] + lamda);
                from[x] = node;
                pq.emplace(dp[x], x);
            }
    }

    return dp[dst] == OO ? -1 : dp[dst];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> src >> dst;

    while (m--)
    {
        int x, y, k, w;

        cin >> x >> y >> k >> w;

        cap[x][y] = k;
        cost[x][y] = w;

        g[x].eb(y);
        g[y].eb(x);
    }

    int ans = 0;

    while (bfs(src, dst))
    {

        while (1)
        {
            int val = dijkstra(src, dst);

            if (val == -1)
                break;

            int node = dst;

            int flow = OO;

            while (node != src)
            {
                int x = from[node];
                flow = min(flow, cap[x][node]);
                node = x;
            }

            node = dst;

            while (node != src)
            {
                int x = from[node];

                ans += cost[x][node] * flow;

                cap[x][node] -= flow;
                cap[node][x] += flow;

                node = x;
            }
        }
    }

    cout << ans;
    return 0;
}