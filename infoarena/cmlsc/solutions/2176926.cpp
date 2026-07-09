#include <bits/stdc++.h>
using namespace std;
int n, m, v[1035], w[1035], dp[1035][1035], i, j, x[1035], k;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f >> n >> m;
    for(i = 1;i <= n;i++)
        f >> v[i];
    for(j = 1;j <= m;j++)
        f >> w[j];
    for(i = 1;i <= n;i++)
        if(w[1] == v[i])dp[1][i] = dp[1][i - 1] + 1;
        else dp[1][i] = dp[1][i - 1];
    for(j = 1;j <= m;j++)
        if(v[1] == w[j])dp[j][1] = dp[j - 1][1] + 1;
        else dp[j][1] = dp[j - 1][1];
    for(j = 2;j <= m;j++)
        for(i = 2;i <= n;i++)
        {
            dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
            if(w[j] == v[i])dp[j][i]++;
        }
    i = n;
    j = m;
    while(i > 1 || j > 1)
    {
        if(v[i] == w[j])
        {
            x[++k] = v[i];
            i--;
            j--;
            continue;
        }
        if(dp[j][i - 1] >= dp[j - 1][i])i--;
        else j--;
    }
    g << k << "\n";
    for(i = k;i > 0;i--)
        g << x[i] << " ";
    return 0;
}
