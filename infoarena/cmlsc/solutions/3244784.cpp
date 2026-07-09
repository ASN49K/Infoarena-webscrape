#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n, m;
int main() {
    in >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= n; i++) {
        in >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        in >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    out << dp[n][m] << '\n';

    int r = n, c = m;
    vector<int> ans;

    while (r > 0 && c > 0) {
        if (a[r] == b[c]) {
            ans.push_back(a[r]);
            r--;
            c--;
        } else {
            if (dp[r - 1][c] > dp[r][c - 1]) {
                r--;
            } else {
                c--;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto it : ans) {
        out << it << ' ';
    }
    return 0;
}
