
#include <bits/stdc++.h>
using namespace std;

#define PB_FILE(nm) \
    freopen(nm ".in", "r", stdin); \
    freopen(nm ".out", "w", stdout)

int main()
{
    PB_FILE("cmlsc");

    const int mxN = 1025;
    int a[mxN]{};
    int b[mxN]{};
    int n, m;

    int dp[mxN][mxN]{};
    int seq[mxN]{};

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", b + i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int len = dp[n][m];
    int k = len - 1, i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            seq[k--] = a[i];
            i--;j--;
        } else if (dp[i-1][j] < dp[i][j-1]) {
            j--;
        } else {
            i--;
        }
    }

    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", seq[i]);
    }
}
