#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,s=0,maxi=1,dp[1010][1010],n,m,a[1010],b[1010],v[1010],k=0;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    fout<<dp[n][m]<<'\n';
    i=n,j=m;
    while(i!=0 && j!=0)
    {
        if(a[i]==b[j])
            v[++k]=a[i],i--,j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    for(i=k;i>=1;i--)
        fout<<v[i]<<' ';

    return 0;
}
