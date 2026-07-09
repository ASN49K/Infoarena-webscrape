// messi < ronaldo    ronaldo has georgina

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define dim (int)(1 << 10) + 5
using namespace std;
const long long INF = LLONG_MAX;
int n, m, dp[dim][dim], v[dim], a[dim], sir[dim], k;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
signed main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        fin >> v[i];
    }
    for(int i = 1; i <= m; ++i)
    {
        fin >> a[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(v[i] == a[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while(i >= 1)
    {
        if(v[i] == a[j])
        {
            sir[++k] = v[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] < dp[i][j - 1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    fout << k << '\n';
    for(int i = k; i >= 1; --i)
    {
        fout << sir[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
