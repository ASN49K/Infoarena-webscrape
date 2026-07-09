#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1050],b[1050],nr,dp[1050][1050],sol[1050],i,j;
int main()
{
    f>>n>>m;
    for(i=1; i<=n; ++i)
        f>>a[i];
    for(i=1; i<=m; ++i)
        f>>b[i];
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
   }
    i=n;
    j=m;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol[++nr]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])i--;
        else j--;
    }
    g<<nr<<'\n';
    for(i=nr; i>=1; i--)
        g<<sol[i]<<' ';
    return 0;
}
