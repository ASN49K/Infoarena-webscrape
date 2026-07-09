#include<cstdio>
#include<algorithm>
using namespace std;
int best,i,j,n,m,a[1060],b[1060],sir[1060],dp[1060][1060];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(j=1;j<=m;j++)
        scanf("%d",&b[j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    i=n;
    j=m;
    while(i>=1||j>=1)
    {
        if(a[i]==b[j])
        {
            sir[++best]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]) j--;
        else i--;
    }
    printf("%d\n",best);
    for(i=best;i>=1;i--)
        printf("%d ",sir[i]);
    return 0;
}
