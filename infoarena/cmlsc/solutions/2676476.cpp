#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int NMAX=1030;///NMAX==MMAX
int n,m,k,a[NMAX],b[NMAX],ans[NMAX],dp[NMAX][NMAX];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int i=1; i<=m; i++)
        f>>b[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else if(dp[i][j]==dp[i-1][j-1]+1)
        {
            i--;
            j--;
            ans[++k]=a[i+1];
        }
    }
    g<<dp[n][m]<<"\n";
    for(int i=k; i>=1; i--)
        g<<ans[i]<<" ";
    return 0;
}
