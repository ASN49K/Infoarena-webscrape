#include <stdio.h>
#include <algorithm>

using namespace std;

int n,m;
int t[1030],v[1030],dp[1030][1030],sol[1030];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);

    for (int i=1;i<=n;i++) scanf("%d",&t[i]);

    for (int i=1;i<=m;i++) scanf("%d",&v[i]);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (t[i]==v[j]) dp[i][j]=dp[i-1][j-1]+1; else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    printf("%d\n",dp[n][m]);

    int i=n,j=m,x=0;

    while (dp[i][j]>0) {
        while (dp[i][j]==dp[i-1][j]) i--;
        while (dp[i][j]==dp[i][j-1]) j--;
        x++; sol[x]=t[i];
        i--; j--;
    }

    for (int i=dp[n][m];i>0;i--) printf("%d ",sol[i]);

    return 0;
}
