#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int length = dp[n][m];
    vector<int> c(length);
    int x = n, y = m, index = length - 1;

    while (x > 0 && y > 0) {
        if (a[x - 1] == b[y - 1]) {
            c[index] = a[x - 1];
            index--;
            x--;
            y--;
        } else if (dp[x - 1][y] >= dp[x][y - 1]) {
            x--;
        } else {
            y--;
        }
    }
    cout << dp[n][m] << endl;
    for (int i = 0; i < length; i++) {
        cout << c[i] << " ";
    }
}
