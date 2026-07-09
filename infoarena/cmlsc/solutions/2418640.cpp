#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int dp[1030][1030];
vector <int> rez;

int main()
{
    int i, j, n, m, v[1030], u[1030];
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (i = 1; i <= m; i++) {
        scanf("%d", &u[i]);
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (v[i] == u[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    i = n; j = m;
    while (dp[i][j] != 0) {
        if (v[i] == u[j]) {
            rez.push_back(v[i]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    printf("%d\n", rez.size());
    for (i = rez.size() - 1; i >= 0; i--) {
        printf("%d ", rez[i]);
    }
    return 0;
}
