#include <iostream>
#include <fstream>

void compute(const int dp[1200][1200], const int *a, const int *b, int n, int m, std::ostream &ostream) {
    if (n == 0 || m == 0) return;

    if (a[n] == b[m]) {
        compute(dp, a, b, n - 1, m - 1, ostream);
        ostream << a[n] << " ";
        return;
    }
    if (dp[n][m - 1] > dp[n - 1][m]) compute(dp, a, b, n, m - 1, ostream);
    else compute(dp, a, b, n - 1, m, ostream);
}

int main() {
    std::ifstream input("cmlsc.in");
    std::ofstream output("cmlsc.out");

    int n, m;
    int a[1025], b[1025];
    int dp[1200][1200] = {0};

    input >> n >> m;

    for (int i = 1; i <= n; ++i) {
        input >> a[i];
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; ++i) {
        input >> b[i];
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    output << dp[n][m] << '\n';

    compute(dp, a, b, n, m, output);

    return 0;
}
