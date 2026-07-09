#include <bits/stdc++.h>

using namespace std;

const int DIM = (1 << 10) + 5;

int a[DIM], b[DIM], dp[DIM][DIM], ans[DIM];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    printf("%d\n", dp[n][m]);
    while(i >= 1 && j >= 1) {
        if(a[i] == b[j]) {
            ans[++ans[0]] = a[i];
            --i, --j;
        }
        else if(dp[i][j - 1] >= dp[i - 1][j]) {
            --j;
        }
        else {
            --i;
        }
    }
    for(int i = ans[0]; i >= 1; --i) printf("%d ", ans[i]);
    return 0;
}
