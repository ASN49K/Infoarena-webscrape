#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int dp[1025][1025],n,m,v[1025],w[1025];
void Solve()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(v[i]==w[j]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    g<<dp[n][m]<<"\n";

}
void Redo()
{
    int i=n,j=m,sol[1025],k=0;
    while(i!=0 && j!=0)
    {

        if(dp[i-1][j]==dp[i][j]) i--;
          if(dp[i][j-1]==dp[i][j]) j--;
          if(dp[i][j-1]!=dp[i][j] && dp[i-1][j]!=dp[i][j]) {sol[++k]=v[i];i--;j--;}
    }
    for(i=k;i>=1;i--)
        g<<sol[i]<<" ";
}
int main()
{
f>>n>>m;
for(int i=1;i<=n;i++)
    f>>v[i];
for(int i=1;i<=m;i++)
    f>>w[i];
    Solve();
    Redo();
}
