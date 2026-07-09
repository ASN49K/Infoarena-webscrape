#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,a[1030],b[1030],dp[1030][1030],d[1030][1030],ans[1030];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
        in>>a[i];
    for(int i=1;i<=m;++i)
        in>>b[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(dp[i][j]<=dp[i-1][j])
            {
                dp[i][j]=dp[i-1][j];
                d[i][j]=1;
            }
            if(dp[i][j]<=dp[i][j-1])
            {
                dp[i][j]=dp[i][j-1];
                d[i][j]=2;
            }
            if(a[i]==b[j]&&dp[i][j]<dp[i-1][j-1]+1)
            {
                dp[i][j]=dp[i-1][j-1]+1;
                d[i][j]=3;
            }
        }
    out<<dp[n][m]<<'\n';
    int i=n,j=m;
    ans[0]=dp[n][m];
    while(i&&j)
    {
        if(d[i][j]==3)
        {
            ans[dp[n][m]--]=a[i];
            --i;
            --j;
        }
        else if(d[i][j]==1)
        {
            --i;
        }
        else if(d[i][j]==2)
        {
            --j;
        }
    }
    for(int i=1;i<=ans[0];++i)
        out<<ans[i]<<' ';
    return 0;
}
