#include <bits/stdc++.h>

using namespace std;

int a[1025];
int b[1025];
int dp[1025][1025];

int main() {
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) fin >> a[i];
    for (int i = 1; i <= m; ++i) fin >> b[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1] + (a[i] == b[j]), max(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    fout << dp[n][m] << '\n';
    vector <int> ans;
    while (n && m) {
        if (dp[n][m] == dp[n - 1][m - 1] + 1 and a[n] == b[m]) {
            ans.push_back(a[n]);
            n -= 1;
            m -= 1;
        } else if (dp[n][m] == dp[n - 1][m]) {
            n -= 1;
        } else {
            m -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) fout << x << ' ';
    return 0;
}
