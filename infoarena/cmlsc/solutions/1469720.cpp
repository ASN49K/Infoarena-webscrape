#include <fstream>
#include <iostream>

using namespace std;

const int MAXN = 1025;
int m, n, dp[MAXN][MAXN], a[MAXN], b[MAXN], subsir[MAXN], best;

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");

    cin >> m >> n;

    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = m, j = n; i;) {
        if (a[i] == b[j]) {
             subsir[++best] = a[i];
             --i, --j;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }

    cout << best << '\n';
    for (int i = best; i; --i) {
        cout << subsir[i] << ' ';
    }

    return 0;
}
