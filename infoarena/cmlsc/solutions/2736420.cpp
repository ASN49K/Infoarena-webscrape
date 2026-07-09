#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1050],b[1050],dp[1050][1050];

void afisare_solutie(int i, int j, int l)
{
    if(l<=0)return;

    if(a[i]==b[j] && dp[i][j]==l)
    {
        afisare_solutie(i-1,j-1,l-1);
        g<<a[i]<<" ";
    }
    else if(a[i]!=b[j])
    {
        if(dp[i-1][j]==l)afisare_solutie(i-1,j,l);
        else afisare_solutie(i,j-1,l);
    }
}

int n,m,i,j;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)f>>a[i];
    for(i=1;i<=m;i++)f>>b[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    g<<dp[n][m]<<'\n';
    afisare_solutie(n,m,dp[n][m]);
    return 0;
}
