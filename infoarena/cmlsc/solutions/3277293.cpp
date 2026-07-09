#include <bits/stdc++.h>

using namespace std;

ifstream in("clmsc.in");
ofstream out("clmsc.out");

int main() {
    short n, m;
    in >> n >> m;

    vector<short> a(n); for (auto& i: a) in >> i;
    vector<short> b(m); for (auto& i: b) in >> i;

    vector<vector<vector<short>>> dp(n + 1, vector<vector<short>>(m + 1));
    for (short i = 1; i <= n; i++) {
        for (short j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].push_back(a[i - 1]);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], [](const vector<short>& x, const vector<short>& y) {
                    return x.size() < y.size();
                });
            }
        }
    }

    out << dp[n][m].size() << "\n";
    for (const auto& i: dp[n][m]) out << i << " ";

    return 0;
}
