#include <cstdio>

using namespace std;

int v[1050], w[1050], dp[1050][1050], sol[1050];

int maxim(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m;

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; ++ i) {
        scanf("%d", &v[i]);
    }
    for(int i = 1; i <= m; ++ i) {
        scanf("%d", &w[i]);
    }

    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            if(v[i] == w[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                sol[dp[i][j]] = v[i];
            } else {
                dp[i][j] = maxim(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    printf("%d\n", dp[n][m]);

    for(int i = 1; i <= dp[n][m]; ++ i) {
        printf("%d ", sol[i]);
    }

    return 0;
}
