#include <iostream>

#define NMAX 1025

int main()
{
    int n, m;
    int v[NMAX], w[NMAX];
    int s[NMAX];
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
            if (v[i] == w[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];

                s[dp[i][j]] = v[i];
            } else
                dp[i][j] = dp[i - 1][j] < dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];

    std::cout << dp[n][m] << '\n';

    for (int i = 1; i <= dp[n][m]; ++i)
        std::cout << s[i] << ' ';

    std::cout << '\n';

    return 0;
}
