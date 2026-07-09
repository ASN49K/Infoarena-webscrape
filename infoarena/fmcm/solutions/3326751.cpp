#include <bits/stdc++.h>

using namespace std;

ifstream fin ("maxflow.in");
ofstream fout ("maxflow.out");

const int inf = 1e9;

vector <int> g[1005];

vector <pair <int, int>> edges;

int n, m, s, dest;

int cost[1005][1005], cap[1005][1005];

int d[1005];

void bellman (int node)
{
    for (int i = 1; i <= n; i++)
        d[i] = inf;
    d[node] = 0;
    for (int i = 1; i <= n; i++)
        for (auto e : edges)
        {
            int x = e.first;
            int y = e.second;
            int c = cost[x][y];
            if (d[x] != inf && d[y] > d[x] + c)
                d[y] = d[x] + c;
        }
}

typedef pair <int, int> pi;

priority_queue <pi, vector <pi>, greater <pi>> q;

int dist[1005], dt[1005], t[1005];
bool sel[1005];

int get_val ()
{
    while (!q.empty () && sel[q.top ().second])
        q.pop ();
    if (q.empty ())
        return -1;
    pi x = q.top ();
    q.pop ();
    return x.second;
}

bool dijkstra (int s)
{
    for (int i = 1; i <= n; i++)
    {
        dt[i] = dist[i] = inf;
        sel[i] = false;
        t[i] = 0;
    }
    while (!q.empty ())
        q.pop ();
    dt[s] = 0;
    dist[s] = 0;
    q.push ({0, s});
    while (!q.empty ())
    {
        int k = get_val ();
        if (k == -1)
            break;
        sel[k] = true;
        for (auto i : g[k])
        {
            if (cap[k][i] > 0)
            {
                int val = dt[k] + cost[k][i] + d[k] - d[i];
                if (dt[i] > val)
                {
                    dt[i] = val;
                    dist[i] = dist[k] + cost[k][i];
                    t[i] = k;
                    q.push ({val, i});
                }
            }
        }
    }
    if (!sel[dest])
        return false;
    for (int i = 1; i <= n; i++)
        if (dt[i] < inf)
            d[i] += dt[i];
    return true;
}

int rez;

void max_flow (int s, int dest)
{
    bellman (s);
    while (dijkstra (s))
    {
        for (int i = 1; i <= n; i++)
            d[i] = dist[i];
        int mn = inf;
        for (int i = dest; i != s; i = t[i])
            mn = min (mn, cap[t[i]][i]);
        rez += mn * dist[dest];

        for (int i = dest; i != s; i = t[i])
        {
            cap[t[i]][i] -= mn;
            cap[i][t[i]] += mn;
        }
    }
}

int main ()
{
    fin >> n >> m >> s >> dest;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        fin >> x >> y >> cap[x][y] >> cost[x][y];
        g[x].push_back (y);
        g[y].push_back (x);
        edges.push_back ({x, y});
        cost[y][x] = -cost[x][y];
    }
    max_flow (s, dest);
    fout << rez;
    return 0;
}
