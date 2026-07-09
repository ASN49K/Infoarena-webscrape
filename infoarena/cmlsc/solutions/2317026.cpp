#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1030][1030];
int v1[1030];
int v2[1030];
int sol[1030];
int main()
{   freopen("cmlsc.in", "r",stdin);
    freopen("cmlsc.out", "w",stdout);
    int n,m,i,j,k=0;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
        scanf("%d", &v1[i]);
    for(i=1; i<=m; i++)
        scanf("%d", &v2[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(v1[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    printf("%d\n", dp[n][m]);
    i=n;
    j=m;
    while(i>0 && j>0){
        if(v1[i]==v2[j]){
            sol[++k]=v1[i];
            i--;
            j--;
        }
        if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(sol+1, sol+dp[n][m]+1);
    for(i=1; i<=k; i++)
        printf("%d ", sol[i]);
    return 0;
}
