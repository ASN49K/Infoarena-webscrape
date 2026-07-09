#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,i,a[1030],b[1030],dp[1030][1030],j,t[1030],c,mx;
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
    mx=dp[n][m]; i=n; j=m;
    cout<<mx<<'\n';
    while(mx>0)
    {
        if(a[i]==b[j]) {t[mx]=a[i]; mx--; i--; j--;}
        else
        {
            if(dp[i-1][j]==mx) --i;
            else --j;
        }
    }
    for(i=1;i<=dp[n][m];i++)
        cout<<t[i]<<" ";
    return 0;
}
