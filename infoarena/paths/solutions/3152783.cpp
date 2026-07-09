#include <bits/stdc++.h>

using namespace std;

ifstream in ("paths.in");
ofstream out ("paths.out");

struct str
{
    long long x, idx;
    bool operator < (const str & aux) const
    {
        return x < aux.x;
    }
};

const long long max_size = 2e3 + 1;

vector <pair <long long, long long>> mc[max_size];
long long dp[max_size], best[max_size], t[max_size];

void dfs (long long nod, long long par, long long val)
{
    dp[nod] = 0;
    best[nod] = 0;
    for (auto f : mc[nod])
    {
        if (f.first == par)
        {
            continue;
        }
        dfs(f.first, nod, f.second);
        if (dp[nod] < dp[f.first])
        {
            dp[nod] = dp[f.first];
            best[nod] = f.first;
        }
    }
    dp[nod] += val;
}

void dfs2 (long long nod, long long par, long long cap)
{
    t[nod] = cap;
    if (best[nod] == 0)
    {
        return;
    }
    dfs2(best[nod], nod, cap);
    for (auto f : mc[nod])
    {
        if (f.first == best[nod] || f.first == par)
        {
            continue;
        }
        dfs2(f.first, nod, f.first);
    }
}

signed main ()
{
    long long n, k;
    in >> n >> k;
    for (long long i = 1; i < n; i++)
    {
        long long x, y, c;
        in >> x >> y >> c;
        mc[x].push_back({y, c});
        mc[y].push_back({x, c});
    }
    for (long long i = 1; i <= n; i++)
    {
        long long ans = 0;
        t[i] = 0;
        dfs(i, 0, 0);
        dfs2(i, 0, i);
        priority_queue <str> pq;
        for (long long j = 1; j <= n; j++)
        {
            if (t[j] == j)
            {
                pq.push({dp[j], j});
            }
        }
        for (long long j = 1; j <= k; j++)
        {
            if (pq.empty())
            {
                break;
            }
            ans += pq.top().x;
            pq.pop();
        }
        out << ans;
        if (i < n)
        {
            out << '\n';
        }
    }
    return 0;
}
