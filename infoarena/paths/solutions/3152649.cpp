#include <bits/stdc++.h>

using namespace std;

ifstream in ("paths.in");
ofstream out ("paths.out");

const long long max_size = 2e3 + 1;

vector <pair <long long, long long>> mc[max_size];
long long dog[max_size], d[max_size], dp[max_size];
pair <long long, long long> t[max_size];

void dfs (long long nod, long long par)
{
    t[nod].first = par;
    for (auto f : mc[nod])
    {
        if (f.first == par)
        {
            continue;
        }
        t[f.first].second = f.second;
        dp[f.first] = dp[nod] + d[f.second];
        dfs(f.first, nod);
    }
}

signed main ()
{
    ios_base::sync_with_stdio(false);
    long long n, k;
    in >> n >> k;
    for (long long i = 1; i < n; i++)
    {
        long long x, y, c;
        in >> x >> y >> c;
        dog[i] = c;
        mc[x].push_back({y, i});
        mc[y].push_back({x, i});
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j < n; j++)
        {
            d[j] = dog[j];
        }
        long long ans = 0;
        for (long long j = 1; j <= k; j++)
        {
            dp[i] = 0;
            dfs(i, 0);
            long long idx = 0, mx = -1;
            for (long long tt = 1; tt <= n; tt++)
            {
               // cout << j << " " << dp[tt] << '\n';
                if (dp[tt] > mx)
                {
                    mx = dp[tt];
                    idx = tt;
                }
            }
         //   cout << '\n';
            ans += mx;
            long long nod = idx;
            while (nod != 0)
            {
                d[t[nod].second] = 0;
                nod = t[nod].first;
            }
        }
        out << ans;
        if (i < n)
        {
            out << '\n';
        }
    }
    return 0;
}
