#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, dp[1055][1055], lcs[1055], a[1055], b[1055];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f >> n >> m;
    for(i = 1; i <= n; i ++)
        f >> a[i];
    for(j = 1; j <= m; j ++)
        f >> b[j];
    for(i = 1; i <= n; i ++)
        if(b[1] == a[i])dp[i][1] = dp[i - 1][1] + 1;
        else dp[i][1] = dp[i - 1][1];
    for(j = 1; j <= m; j ++)
        if(a[1] == b[j])dp[1][j] = dp[1][j - 1] + 1;
        else dp[1][j] = dp[1][j - 1];
    for(i = 2; i <= n; i ++)
        for(j = 2; j <= m; j ++)
            if(a[i] == b[j])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    g << dp[n][m] << "\n";
    i = n;
    j = m;
    while(dp[i][j] > 0)
    {
        if(a[i] == b[j])
        {
            lcs[dp[i][j]] = a[i];
            i --;
            j --;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])i --;
            else j --;
        }
    }
    for(i = 1; i <= dp[n][m]; i ++)
        g << lcs[i] << " ";
    return 0;
}
