#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1050;
int n, m;
int v1[MAXN], v2[MAXN];
int dp[MAXN][MAXN];
int main() {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v1[i];
    for (int j = 1; j <= m; j++) cin >> v2[j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    vector<int> rsp;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (v1[i] == v2[j]) {
            rsp.push_back(v1[i]);
            i--; j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(rsp.begin(), rsp.end());
    cout << dp[n][m] << "\n";
    for (auto x : rsp) cout << x << " ";
    cout << "\n";
    return 0;
}
