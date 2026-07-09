#include <bits/stdc++.h>
#define N_MAX 1026
using namespace std;
int m, n, i, j, k;
int a[N_MAX], b[N_MAX], lcs[2 * N_MAX], dp[N_MAX][N_MAX];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.OUT");

    f >> m >> n;

    for(i = 1; i <= m; i ++)
        f >> a[i];

    for(i = 1; i <= n; i ++)
        f >> b[i];
    /// stabilim recurentele particulare

    if(a[1] == b[1]) dp[1][1] = 1;
                else dp[1][1] = 0;
    // recurenta pe prima linie
    for(i = 2; i < m; i ++)
        if(b[1] == a[i]) dp[1][i] = 1;
                    else dp[1][i] = dp[1][i - 1];
    // recurenta pe prima coloana
    for(i = 2; i < n; i ++)
        if(a[1] == b[i]) dp[i][1] = 1;
                    else dp[i][1] = dp[i - 1][1];
    /// stabilim recurenta generala
    for(i = 2; i <= n; i ++)
     {
        for(j = 2; j <= m; j ++)
        {
            if(b[i] == a[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j]=max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
     }
    i = n; j = m;
    while(i)
    {
        if(b[i] == a[j])
        {
            lcs[++ k] = a[j];
            i --;
            j --;
        }
        else
        {
            if(dp[i][j - 1] >= dp[i - 1][j]) j --;
                                        else i --;
        }
    }

    g << dp[n][m] << "\n";
    for(i = dp[n][m]; i >= 1; i --)
        g << lcs[i] << " ";
    return 0;
}
