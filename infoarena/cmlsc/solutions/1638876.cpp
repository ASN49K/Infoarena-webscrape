#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int dp[1026][1026],v[1026],w[1026],best[1026*1026];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&v[i]);
    for (int i=1; i<=m; ++i)
        scanf("%d",&w[i]);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            if (v[i]==w[j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    printf("%d\n",dp[n][m]);
    int i,j;
    for (i=n,j=m; i>=1,j>=1;)
    {
        if (v[i]==w[j])
        {
            best[++k]=v[i];
            --i;
            --j;
        }
        else
        {
            if (dp[i-1][j]>=dp[i][j-1])
                --i;
            else
                --j;
        }
    }
    for (int i=k;i>0;--i)
        printf("%d ",best[i]);
    return 0;
}
