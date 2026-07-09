#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

long long n,m,i,j,a[1050],b[1050],dp[1050][1050];

void recons(int N, int M, int k)
{
    if(k>0)
    {
        if(a[N]==b[M])
        {
            recons(N-1,M-1,k-1);
            g<<a[N]<<" ";
        }
        else
        {
            if(dp[N-1][M]>=dp[N][M-1])recons(N-1,M,k);
            else recons(N,M-1,k);
        }
    }
}

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)f>>a[i];
    for(i=1;i<=m;i++)f>>b[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    g<<dp[n][m]<<'\n';
    recons(n,m,dp[n][m]);
    return 0;
}
