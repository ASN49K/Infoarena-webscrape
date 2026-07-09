#include <bits/stdc++.h>
#define Nmax 1025
using namespace std;
int a[Nmax], b[Nmax], dp[Nmax][Nmax], lcs[Nmax], i, j, n, m, k;
int main ()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f >> n >> m;
    for(i = 1; i <= n; i ++)
        f >> a[i];
    for(i = 1; i <= m; i ++)
        f >> b[i];
    for(i = 1; i <= n; i ++)
        for(j = 1; j <= m; j ++)
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    i = n, j = m;
    while(i)
    {
        if(a[i] == b[j])
        {
            lcs[++ k] = char(b[j]);
            i --;
            j --;
        }
        else
        {
            if(dp[i][j - 1] >= dp[i - 1][j]) j --;
                                        else i --;
        }
    }
    g << k << "\n";
    for(i = dp[n][m]; i >= 1; i --)
        g << lcs[i] << " ";
    return 0;
}
