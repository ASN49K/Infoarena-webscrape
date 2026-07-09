#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030],a[1030],b[1030],sol[1030];

int main()
{
    int n,m,i,j,k;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    k=dp[n][m];
    int kk=k;
    i=n;
    j=m;
    while(dp[i][j]!=0)
    {
        if(a[i]==b[j])
            sol[k]=a[i],k--,i--,j--;
        else
            if(dp[i][j-1]>dp[i-1][j])
            j--;
        else
            i--;
    }
    fout<<kk<<'\n';
    for(i=1;i<=kk;i++)
        fout<<sol[i]<<" ";
    return 0;
}
