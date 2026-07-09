#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1030],b[1030],i,j,L,dp[1030][1030],c[1030];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++) scanf("%d",&b[i]);
    dp[0][0]=dp[0][1]=dp[1][0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d\n",dp[n][m]); L=dp[n][m];
    for(i=n,j=m;L;)
    {
        if(a[i]==b[j]) c[L]=a[i],i--,j--,L--;
        else
            if(dp[i][j]==dp[i-1][j]) i--;
            else j--;
    }
    for(i=1,L=dp[n][m];i<=L;i++) printf("%d ",c[i]);
    return 0;
}
