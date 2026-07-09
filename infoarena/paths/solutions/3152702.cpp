#include <bits/stdc++.h>

using namespace std;

ifstream in ("paths.in");
ofstream out ("paths.out");

struct str
{
    int x, idx;
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
    t[nod] = par;
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
        priority_queue <str> pq;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (auto f : mc[j])
            {
                if (f.first == t[j] || best[j] == f.first)
                {
                    continue;
                }
                pq.push({dp[f.first], f.first});
            }
        }
        for (int j = 1; j <= k; j++)
        {
            if (pq.empty())
            {
                break;
            }
            ans += pq.top().x;
            //out << pq.top().x << " " << pq.top().idx << '\n';
            int idx = pq.top().idx;
            pq.pop();
            /*
            for (auto f : mc[idx])
            {
                if (f.first == t[idx] || f.first == best[idx])
                {
                    continue;
                }
               // out << dp[f.first] << '\n';
                pq.push({dp[f.first], f.first});
            }
            */
        }
       // out << '\n' << '\n';
        out << ans;
        if (i < n)
        {
            out << '\n';
        }
    }
    return 0;
}
