#include <stdio.h>
#define max(a, b) a>b?a:b

int v[0x401], w[0x401], dp[0x401][0x401], n, m, l, sir[0x401];
int main (void) {
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    int i, j;
    for (i=1; i<=n; i++)
        scanf ("%d", &v[i]);
    for (j=1; j<=m; j++)
        scanf ("%d", &w[j]);
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (v[i]==w[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    for (i=n, j=m; i;)
        if (v[i]==w[j])
            sir[++l]=v[i], i--, j--;
        else
            if (dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
    printf ("%d\n", l);
    for (i=l; i; i--)
        printf ("%d ", sir[i]);
    return 0;
}
