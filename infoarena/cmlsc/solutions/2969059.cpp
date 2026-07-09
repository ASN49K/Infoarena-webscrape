#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int dp[100][100],n,m,i,j,a[100],b[100];
int main()
{
    ///FAZA 1
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];
    if(a[1]==b[1]) dp[1][1]=1;
        else dp[1][1]=0;
    /*1*/for(i=2; i<=n; i++)
        if(b[1]==a[i]) dp[1][i]=1;
            else dp[1][i]=dp[1][i-1];
    /*2*/for(j=2; j<=m; j++)
        if(a[1]==b[j]) dp[j][1]=1;
            else dp[j][1]=dp[j-1][1];
    ///FAZA 2
    for(i=2; i<=m; i++)
        for(j=2; j<=n; j++)
            if(b[i]==a[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    ///FAZA 3
    for(i=1; i<=m; i++)
    {
     for(j=1; j<=n; j++)
            g<<dp[i][j]<<" ";
     g<<'\n';
    }
    ///FAZA 4
    for(i=m; i>0;)
        for(j=n; j>0; j--)
            if(dp[i-1][j]<dp[i][j] && dp[i][j-1]<dp[i][j])
            {
                g<<a[j]<<" ";
                i--;
                j++;
            }
                else if(dp[i][j-1]<dp[i][j]) i--,j++;
return 0;
}
