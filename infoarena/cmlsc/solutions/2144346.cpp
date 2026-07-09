#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1050],b[1050],dp[1050][1050];

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
       {fin>>b[i];}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=max(max(dp[i][j-1] ,dp[i-1][j]),min(dp[i][j-1] ,dp[i-1][j])+(a[i]==b[j]));
        }
    fout<<dp[n][m]<<"\n";
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(dp[i][j]>dp[i-1][j]&&dp[i][j]>dp[i][j-1]) fout<<a[i]<<" ";
    fout<<"\n";
    return 0;
}
