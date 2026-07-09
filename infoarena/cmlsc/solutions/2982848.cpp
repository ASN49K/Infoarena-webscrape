#include <fstream>

#define DIM 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int v1[DIM], v2[DIM], dp[DIM][DIM];
int ansDIM, ans[DIM];

int main() {
    f >> n >> m;

    for (int i = 1; i <= n; i++) {
        f >> v1[i];
    }

    for (int i = 1; i <= m; i++) {
        f >> v2[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    g << dp[n][m] << "\n";

    for (int i = n, j = m; i && j;) {
        if (v1[i] == v2[j]) {
            ans[++ansDIM] = v1[i];
        }
        if (dp[i - 1][j] < dp[i][j - 1]) {
            j--;
        } else {
            i--;
        }
    }

    for (int i = ansDIM; i >= 1; i--) {
        g << ans[i] << " ";
    }

    return 0;
}