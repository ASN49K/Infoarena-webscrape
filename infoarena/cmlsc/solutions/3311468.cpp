#include <bits/stdc++.h>

std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");

int main() {
    int m, n;
    in >> m >> n;

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    std::vector<int> A(m);
    std::vector<int> B(n);

    for (int i = 0; i < m; i++) {
        in >> A[i];
    }

    for (int i = 0; i < n; i++) {
        in >> B[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::vector<int> ans;

    int l = m, r = n;
    while (l > 0 && r > 0) {
        if (A[l - 1] == B[r - 1]) {
            ans.push_back(A[l - 1]);
            l--;
            r--;
        } else {
            if (dp[l - 1][r] > dp[l][r - 1]) {
                l--;
            } else {
                r--;
            }
        }
    }

    std::reverse(ans.begin(), ans.end());
    
    out << ans.size() << '\n';
    for (auto it : ans) {
        out << it << " ";
    }

    return 0;
}