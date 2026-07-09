#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
const int nmax = 350;
int flux[nmax + 1][nmax + 1], cap[nmax + 1][nmax + 1];
int t[nmax + 1], dist[nmax + 1], val[nmax + 1];
long long cost;
vector <pair <int, int>> g[nmax + 1];
priority_queue <pair <int, int>> pq;
int s, d, maxpush, x, y, c, z;
bool solve(int n)
{
    for(int i = 1; i <= n; i++)
        dist[i] = inf;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty())
    {
        x = pq.top().second;
        y = -pq.top().first;
        pq.pop();
        if(y != dist[x])
            continue;
        for(auto z : g[x])
        {
            if(flux[x][z.first] < cap[x][z.first] && dist[z.first] > dist[x] + z.second + val[x] - val[z.first])
            {
                t[z.first] = x;
                dist[z.first] = dist[x] + z.second + val[x] - val[z.first];
                pq.push({-dist[z.first], z.first});
            }
        }
    }
    maxpush = inf;
    for(int nod = d; nod != s; nod = t[nod])
        maxpush = min(maxpush, cap[t[nod]][nod] - flux[t[nod]][nod]);
    if(!maxpush)
        return 0;
    for(int nod = d; nod != s; nod = t[nod])
    {
        flux[nod][t[nod]] -= maxpush;
        flux[t[nod]][nod] += maxpush;
    }
    cost += maxpush * (dist[d] + val[d]);
    for(int i = 1; i <= n; i++)
        val[i] = dist[i] + val[i];
    return 1;
}
void bellman(int n)
{
    for(int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[s] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(auto y : g[j])
            {
                if(cap[j][y.first] && dist[y.first] > dist[j] + y.second)
                    dist[y.first] = dist[j] + y.second;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        val[i] = dist[i];
}
int main()
{
    freopen("fmcm.in", "r", stdin);
    freopen("fmcm.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, i;
    cin >> n >> m >> s >> d;
    for(i = 1; i <= m; i++)
    {
        cin >> x >> y >> c >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, -z});
        cap[x][y] = c;
    }
    bellman(n);
    while(solve(n));
    cout << cost;
    return 0;
}
