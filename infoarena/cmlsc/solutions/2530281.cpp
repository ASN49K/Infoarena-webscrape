#include <bits/stdc++.h>

using namespace std;

const int len = 2 << 9;
int m, n, a[len], b[len], dp[len][len], sol[len], cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }

    cout << dp[m][n] << "\n";

    while (dp[m][n]) {
        if (a[m] == b[n]) {
            sol[cnt++] = a[m];
            m--;
            n--;
        }

        else if (dp[m][n - 1] < dp[m - 1][n])
            m--;

        else
            n--;
    }

    for (int i = cnt; i >= 1; i--)
        cout << sol[i] << " ";
}
