#include <bits/stdc++.h>

using namespace std;

#define TITLE "cmlsc"
#define ll long long
#define MaxN 1034

ifstream f (TITLE".in");
ofstream g (TITLE".out");

int dp[MaxN][MaxN];
int A[MaxN],B[MaxN];

int path(int i, int j, int steps)
{
    if(steps==0)
        return 0;
    if(A[i]==B[j])
    {
        path(i-1, j-1, steps-1);
        g<<A[i]<<' ';
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
            path(i-1,j,steps);
        else
            path(i,j-1,steps);
    }
    return 0;
}

int solve()
{
    int n,m;
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>A[i];
    for(int i=1; i<=m; i++)
        f>>B[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    g<<dp[n][m]<<'\n';
    path(n,m,dp[n][m]);
    return 0;

}

int main()
{
    solve();
    return 0;
}
