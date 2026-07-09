#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[1030],b[1030],dp[1030][1030],sol[1030],maxim;

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int i=1;i<=m;++i)
        f>>b[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    g<<dp[n][m]<<'\n';
    maxim=dp[n][m];
    int i=n,j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            sol[maxim]=a[i];
            maxim--;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(int i=1;i<=dp[n][m];++i)
        g<<sol[i]<<' ';
    return 0;
}
