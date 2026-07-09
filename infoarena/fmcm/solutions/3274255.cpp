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
int from[MAX + 5], dp[MAX + 5], old_cost[MAX + 5], rdp[MAX + 5];
int cap[MAX + 5][MAX + 5], cost[MAX + 5][MAX + 5];
vector<int> g[MAX + 5];

bool bfs(int src, int dst) /// verific daca pot ajunge din src in dst
{
    fill(old_cost, old_cost + MAX + 2, OO);
    queue<int> que;

    que.emplace(src);
    old_cost[src] = 0;

    while (!que.empty())
    {
        int node = que.front();

        que.pop();

        for (auto x : g[node])
            if (cap[node][x] > 0 and old_cost[x] > old_cost[node] + cost[node][x])
            {
                old_cost[x] = old_cost[node] + cost[node][x];
                que.emplace(x);
            }
    }

    return old_cost[dst] != OO;
}

int dijkstra(int src, int dst) /// aflu path-ul de cost minim de la src la dst
{
    memset(from, 0, sizeof(from));
    fill(dp, dp + MAX + 2, OO);
    fill(rdp, rdp + MAX + 2, 0);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.emplace(0, src);
    dp[src] = rdp[src] = 0;

    while (!pq.empty())
    {
        int w, node;
        tie(w, node) = pq.top();

        pq.pop();

        for (auto x : g[node])
            if (cap[node][x] > 0)
            {
                int new_cost = dp[node] + cost[node][x];
                new_cost += old_cost[node] - old_cost[x];

                if (new_cost < dp[x])
                {
                    dp[x] = new_cost;
                    from[x] = node;
                    rdp[x] = rdp[node] + cost[node][x];
                    pq.emplace(dp[x], x);
                }
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
        cost[y][x] = -w;

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

            while (node != src) /// imi aflu fluxl maxim pe path-ul de cost minim
            {
                int x = from[node];
                flow = min(flow, cap[x][node]);
                node = x;
            }

            ans += flow * rdp[dst];

            node = dst;

            while (node != src) /// dau update la path
            {
                int x = from[node];

                cap[x][node] -= flow;
                cap[node][x] += flow;

                node = x;
            }
        }
    }

    cout << ans;
    return 0;
}
