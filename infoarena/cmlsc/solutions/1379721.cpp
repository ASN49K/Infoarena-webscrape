#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int sir[1030],best,i,j,n,m,dp[1030][1030],a[1030],b[1030];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
   // printf("%d\n",dp[n][m]);
    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
        {
            if(a[i]==b[j])
                sir[++best]=a[i], i--, j--;
            else if(dp[i-1][j]<dp[i][j-1])  j--;
            else i--;
        }
    printf("%d\n",best);
    for(i=best;i>=1;i--)
        printf("%d ",sir[i]);
    return 0;
}
