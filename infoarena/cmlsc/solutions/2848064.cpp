#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1030],b[1030],dp[1030][1030],i,j,ind[1030];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
    {
        dp[i][j]=dp[i-1][j-1]+1;
        ind[dp[i][j]]=a[i];
    }
           else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    g<<dp[n][m]<<'\n';
    for(i=1;i<=dp[n][m];i++)
        g<<ind[i]<<" ";
    return 0;
}
