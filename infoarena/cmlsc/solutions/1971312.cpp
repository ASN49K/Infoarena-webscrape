#include <iostream>
#include <cstdio>
#define maxn 1026
using namespace std;


int a[maxn],b[maxn],n,m,dp[maxn][maxn],sol[maxn],k;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;++i)
        scanf("%d",&b[i]);
    int i=1,j=1;
    for (;i<=n;++i)
        for (j=1;j<=m;++j)
            if (a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    i=n,j=m;
    while (i>=1 && j>=1)
    {
        if (a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;j--;
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    printf("%d\n",dp[n][m]);
    for (int i=k;i>=1;--i)
        printf("%d ",sol[i]);
    return 0;
}
