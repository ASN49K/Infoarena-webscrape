#include "bits/stdc++.h"
 
using namespace std;
 
using ld = long double;
using ll = long long;
using ull = unsigned long long;
 
#if defined(ONPC)
#include "bits/debug.h"
#endif

const int mxN = 5e6;
int v[mxN];
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        if (a[i] == b[0]) dp[i][0] = 1;
        if (i != 0) dp[i][0] = max(dp[i][0], dp[i - 1][0]);
    }

    for (int j = 0; j < m; ++j) {
        if (b[j] == a[0]) dp[0][j] = 1;
        if (j != 0) dp[0][j] = max(dp[0][j], dp[0][j - 1]);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n - 1][m - 1] << "\n";

    int x = n - 1, y = m - 1;
    vector<int> pos;
    while (x >= 0 && y >=  0) {
        if (a[x] == b[y]) {
            pos.push_back(a[x]);
            --x, --y;
        } else {
            if (x == 0) --y;
            else if (y == 0) --x;
            else if (dp[x - 1][y] >= dp[x][y - 1]) --x;
            else --y;
        }
    }

    for (int i = (int)pos.size() - 1; i >= 0; --i) cout << pos[i] << ' ';
    cout << "\n";
}
