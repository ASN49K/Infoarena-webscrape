#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1030],b[1030];
int N,M,i,j,dp[1030][1030];

void Dynamic()
{
    for(i=1;i<=M;i++)
    for(j=1;j<=N;j++)
    {
        if(a[i]==b[j])dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}

void Print(int x,int y,int level)
{
    for(int i=x;i>0;i--)
    for(int j=y;j>0;j--)
    if(dp[i][j]==level and a[i]==b[j])
    {
        Print(i-1,j-1,level-1);
        g<<a[i]<<" ";return;
    }
}
int main()
{
    f>>M>>N;
    for(i=1;i<=M;i++)f>>a[i];
    for(i=1;i<=N;i++)f>>b[i];
    Dynamic();
    g<<dp[M][N]<<"\n";
    Print(M,N,dp[M][N]);
    return 0;
}
