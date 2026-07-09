#include <fstream>
#include <cstring>
using namespace std;

ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int i,j,n,m,dp[1005][1005],a[1005],b[1005],k,c[1005];

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];
    for(i=2; i<=n+1; i++)
        for(j=2; j<=m+1; j++)
        {
            if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    c[++k]=a[i-1];
                }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    cout<<dp[n+1][m+1]<<endl;
    for(i=1;i<=k;i++)
        cout<<c[i]<<' ';
}
