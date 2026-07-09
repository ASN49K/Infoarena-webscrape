#include <iostream>
#include <cstdio>
using namespace std;

int m,n;
int v[1030],w[1030];
int dp[1030][1030];
int best[1030],k;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    for (int j=1; j<=m; ++j)
        scanf("%d",&w[j]);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if (v[i]==w[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    printf("%d\n",dp[n][m]);
    int i=n,j=m;
    while (!(i<=1 && j<=1))
    {
        if (v[i]==w[j])
        {
            best[++k]=v[i];
            --i;--j;
        }
        else
        {
            if (dp[i-1][j] < dp[i][j-1] && j!=1)
                --j;
            else
                --i;
        }
    }
    while (k)
        {
            printf("%d ",best[k]);
            --k;
        }
    return 0;
}
