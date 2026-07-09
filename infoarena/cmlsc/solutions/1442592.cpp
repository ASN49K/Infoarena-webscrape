#include <stdio.h>
#define maxx(a, b) a > b ? a : b;
#define NMAX 1025

int n, m, first[NMAX], second[NMAX], dp[NMAX][NMAX], ans[NMAX];

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &first[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &second[i]);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <=m; ++j) {
            if(first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = maxx(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("%d\n", dp[n][m]);

    int i = n;
    int j = m;
    int nAns = 0;

    while(i > 0 && j > 0) {
        if(first[i] == second[j]) {
            ans[nAns++] = first[i];
            --i; --j;
        }
        else {
            if(dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            }
            else {
                --j;
            }
        }
    }

    for(i = nAns - 1; i >= 0; --i)
        printf("%d ", ans[i]);

    return 0;
}
