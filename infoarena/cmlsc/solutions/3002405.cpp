#include <bits/stdc++.h>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[10005], b[10005], n, m, dp[1030][1030], sol[1030], k;
int main()
{
    int i, j;
    in >> n >> m;
    for(i = 1; i <= n; i++)
        in >> a[i];
    for(i = 1; i <= m; i++)
        in >> b[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    i = n; j = m;
    while(i >= 1 and j >= 1)
    {
        if(a[i] == b[j])
        {
            sol[++k] = a[i];
            i--; j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }
    out << dp[n][m] << "\n";
    for(i = k; i >= 1; i--)
        out << sol[i] << " ";
    return 0;
}
