#include <cstdio>
#include <algorithm>

using namespace std;
/// https://infoarena.ro/problema/cmlsc

#define NMAX 1025

int dp[NMAX][NMAX], a[NMAX], b[NMAX], sir[NMAX];
int m, n, i, j, x;

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &m, &n);

    for (i=1; i<=m; i++)
        scanf("%d", &a[i]);

    for (i=1; i<=n; i++)
        scanf("%d", &b[i]);

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (b[i] == a[j])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    

    i=n, j=m;
    while (dp[i][j] != 0)
    {
        if (dp[i][j] != max(dp[i-1][j], dp[i][j-1]))
            sir[x] = b[i], x++, i--, j--;
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;
    }

    printf("%d%s", dp[n][m], "\n");
    for (i=x-1; i>=0; i--)
        printf("%d%s", sir[i], " ");

    return 0;
}