#include <cstdio>

using namespace std;
int n,m,i,a[1025],b[1025],dp[1025][1025],j,sol[1025],k;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
        }
    printf("%d\n",dp[n][m]);
    for(i=n,j=m,k=0;dp[i][j];)
    {
        if(a[i]==b[j]){sol[++k]=a[i];i--;j--;}
        else
        if(dp[i][j-1]>=dp[i-1][j])j--;
        else i--;

    }
    for(;k;k--)
        printf("%d ",sol[k]);
    return 0;
}
