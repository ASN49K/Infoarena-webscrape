#include <iostream>
#include <fstream>
#define MAXN 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,dp[MAXN][MAXN],v1[MAXN],v2[MAXN],afis[MAXN];
int main()
{
    f>>n>>m;
    for (int i=1; i<=n; i++)
    {
        f>>v1[i];
    }
    for (int j=1; j<=m; j++)
    {
        f>>v2[j];
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if (v1[i]==v2[j])
            {
                if (dp[i][j]<dp[i-1][j-1]+1)
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
    }
    g<<dp[n][m]<<'\n';
    int i=n,j=m,l=dp[n][m];
    while (i>=1 && j>=1)
    {
        if (v1[i]==v2[j])
        {
            afis[l]=v1[i];
            l--;
            i--;
            j--;
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    for (int i=1; i<=dp[n][m]; i++)
    {
        g<<afis[i]<<' ';
    }
    return 0;
}