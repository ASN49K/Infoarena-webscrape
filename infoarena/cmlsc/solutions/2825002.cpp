#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,i,a[1030],b[1030],dp[1030][1030],j,t[1030],c;
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++) cin>>a[i];
    for(i=1; i<=m; i++) cin>>b[i];
    for(i=1; i<=n; i++)
    {
        for(j=1;j<=m;j++)
        {
           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
        }
    }
    cout<<dp[n][m]<<'\n';
    c=1;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(dp[i][j]==c) {cout<<a[i]<<" "; c++;}
    }
    return 0;
}
