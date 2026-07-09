#include <bits/stdc++.h>

using namespace std;

ifstream in("clmsc.in");
ofstream out("clmsc.out");

int main() {
    int n, m;
    in >> n >> m;

    vector<int> a(n); for (auto& i: a) in >> i;
    vector<int> b(m); for (auto& i: b) in >> i;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j].push_back(a[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];\
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], [](const vector<int>& x, const vector<int>& y) {
                    return x.size() < y.size();
                });
            }
        }
    }

    for (const auto& i: dp[n][m]) out << i << " ";

    return 0;
}