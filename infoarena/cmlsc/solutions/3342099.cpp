#include <iostream>

#define NMAX 1025

int main()
{
    int n, m, l = 0;
    int v[NMAX], w[NMAX], s[NMAX];
    int dp[NMAX][NMAX];

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        std::cin >> v[i];

    for (int i = 1; i <= m; ++i)
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

    std::cout << dp[n][m] << '\n';

    while (n >= 1 && m >= 1 && dp[n][m]) {
        while (dp[n - 1][m] == dp[n][m])
            --n;

        while (dp[n][m - 1] == dp[n][m])
            --m;

        s[++l] = v[n];

        --n;
        --m;
    }

    for (int i = l; i > 0; --i)
        std::cout << s[i] << ' ';

    std::cout << '\n';

    return 0;
}
