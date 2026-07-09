#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int dp[1025][1025],a[1025],b[1025],sol[1025];


int main()
{int n,m,i,j,k,x=0;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    if (a[i]==b[j])
        dp[i][j]=dp[i-1][j-1]+1;
    else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    g<<dp[n][m]<<'\n';
    k=dp[n][m];
    i=n;
    j=m;
    while (k>0 && (i>0 || j>0))
    {
        if (a[i]==b[j])
        {
            k--;
            sol[++x]=a[i];
            i--;
            j--;
        }
        else
            if (dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
    }
    for (i=x;i>=1;i--)
        g<<sol[i]<<' ';
}
