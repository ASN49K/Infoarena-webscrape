#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int MAX = (1 << 10) + 5;

int n, m, a[MAX], b[MAX], dp[MAX][MAX], sir[MAX], i, j;

int main()
{
    f >> n >> m;

    for (i = 1; i <= n; ++i) {
        f >> a[i];
    }

    for (i = 1; i <= m; ++i) {
        f >> b[i];
    }

    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (i = n, j = m; i; ) {
        if (a[i] == b[j]) {
            sir[++sir[0]] = a[i];
             i--;
             j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1]) {
            j--;
        }
        else {
            i--;
        }
    }

    g << sir[0] << '\n';

    for (i = sir[0]; i; --i) {
        g << sir[i] << ' ';
    }

    return 0;
}
