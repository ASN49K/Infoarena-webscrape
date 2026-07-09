#include    <iostream>
#include    <stdio.h>
#include    <cstring>

using namespace std;

const int nMax = 1030;

int n,m;
int a[nMax], b[nMax];
int dp[nMax][nMax];
int sir[nMax];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; ++i)
        scanf("%d", &a[i]);

    for(int j=1; j<=m; ++j)
        scanf("%d", &b[j]);

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(a[i] == b[j])dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    printf("%d\n", dp[n][m]);

    int cnt = 0;
    for(int i=n, j=m; i>=1 && j>=1;)
        if(a[i] == b[j])
        {
            sir[++cnt] = a[i];
            --i;
            --j;
        }
        else if(dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;

    for(int i = cnt; i>=1; --i)
        printf("%d ", sir[i]);

    return 0;
}
