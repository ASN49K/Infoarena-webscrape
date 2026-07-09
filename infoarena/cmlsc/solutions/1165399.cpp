#include <algorithm>
#include <cstdio>

using namespace std;

const int N=1030;

int a[N], b[N], dp[N][N], c[N];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, i, j, sol=0, p;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++) scanf("%d", &a[i]);
    for(i=1;i<=m;i++) scanf("%d", &b[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            if(a[i]==b[j]&&dp[i][j]<dp[i-1][j-1]+1) dp[i][j]=dp[i-1][j-1]+1;
            sol=max(sol, dp[i][j]);
        }
    }
    p=sol;
    for(i=n, j=m;i&&j;)
    {
        if(a[i]==b[j])
        {
            c[p--]=a[i];
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]) j--;
        else i--;
    }
    printf("%d\n", sol);
    for(i=1;i<=sol;i++) printf("%d ", c[i]);
}
