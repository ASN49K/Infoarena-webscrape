#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N = 1030;

int n,m,i,j,a[N],b[N],dp[N][N];
void afisare(int,int);
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)f>>a[i];
    for(i=1;i<=n;i++)f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            dp[i][j]=a[i]==b[j]?dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
    g<<dp[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
void afisare(int li,int co)
{
    if(dp[li][co]==0)
        return;
    if(a[li]==b[co])
    {
        afisare(li-1,co-1);
        g<<a[li]<<' ';
    }
    else
        if(dp[li-1][co]>=dp[li][co-1])
            afisare(li-1,co);
            else
            afisare(li,co-1);
}
