#include <iostream>

#define NMAX 1024

int main()
{
    int n, m, t;
    int v[NMAX], w[NMAX], s[NMAX];
    int dp[NMAX + 1][NMAX + 1];

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
        std::cin >> v[i];

    for (int i = 0; i < m; ++i)
        std::cin >> w[i];

    for (int nv = 0; nv <= n; ++nv)
        dp[nv][0] = 0;

    for (int nw = 0; nw <= m; ++nw)
        dp[0][nw] = 0;

    for (int nv = 1; nv <= n; ++nv)
        for (int nw = 1; nw <= m; ++nw)
            if (v[nv - 1] == w[nw - 1])
                dp[nv][nw] = 1 + dp[nv - 1][nw - 1];
            else
                dp[nv][nw] = dp[nv - 1][nw] < dp[nv][nw - 1] ? dp[nv][nw - 1] : dp[nv - 1][nw];

    t = dp[n][m];

    for (int nv = n, nw = m, ns = t; nv > 0 && nw > 0;) {
        if (dp[nv][nw] == dp[nv - 1][nw]) {
            --nv;
        } else if (dp[nv][nw] == dp[nv][nw - 1]) {
            --nw;
        } else /* dp[nv][nw] == dp[nv - 1][nw - 1] */ {
            s[ns - 1] = v[nv - 1];

            --nv;
            --nw;
            --ns;
        }
    }

    std::cout << t << '\n';

    for (int i = 0; i < t; ++i)
        std::cout << s[i] << ' ';

    std::cout << '\n';

    return 0;
}
