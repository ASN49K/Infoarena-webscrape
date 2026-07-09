#include <iostream>

#define NMAX 1024

int main()
{
    int n, m, t = 0;
    int v[NMAX], w[NMAX], s[NMAX];
    int dp[NMAX + 1][NMAX + 1];

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    for (int i = 0; i < m; ++i)
        std::cin >> w[i];

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    for (int i = 0; i <= m; ++i)
        dp[0][i] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (v[i] == w[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];

    while (n > 0 && m > 0) {
        if (dp[n][m] == dp[n - 1][m]) {
            --n;
        } else if (dp[n][m] == dp[n][m - 1]) {
            --m;
        } else /* dp[n][m] == dp[n - 1][m - 1] */ {
            s[t++] = v[n - 1];

            --n;
            --m;
        }
    }

    std::cout << t << '\n';

    for (int i = 0; i < t; ++i)
        std::cout << s[i] << ' ';

    std::cout << '\n';

    return 0;
}
