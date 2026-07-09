#include <iostream>
#include <fstream>
#include <algorithm>

void compute(int dp[1025][1025], int *a, int *b, int n, int m, std::ostream &out) {
    if (n == 0 || m == 0) return;
    if (a[n] == b[m]) {
        compute(dp, a, b, n - 1, m - 1, out);
        out << a[n] << " ";
    } else if (dp[n - 1][m] >= dp[n][m - 1]) {
        compute(dp, a, b, n - 1, m, out);
    } else {
        compute(dp, a, b, n, m - 1, out);
    }
}

int main() {
    std::ifstream in("cmlsc.in");
    std::ofstream out("cmlsc.out");

    int n, m;
    in >> n >> m;

    int a[1025], b[1025];
    int dp[1025][1025] = {0};

    for (int i = 1; i <= n; ++i) {
        in >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        in >> b[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    out << dp[n][m] << "\n";
    if (dp[n][m] > 0) {
        compute(dp, a, b, n, m, out);
    }

    return 0;
}