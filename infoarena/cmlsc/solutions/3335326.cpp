#include <bits/stdc++.h>
using namespace std;

int a[1025], b[1025], dp[1030][1030];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef LOCAL
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
#endif

    int m, n; cin >> m >> n;
    for(int i = 0; i < m; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    for(int i = m - 1; i >= 0; --i) {
        for(int j = n - 1; j >= 0; --j) {
            dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i+1][j+1]+1);
            }
        }
    }

    cout << dp[0][0] << '\n';

    vector<int> rez;
    for(int i = 0, j = 0; i < m && j < n; ) {
        if(a[i] == b[j] && dp[i][j] == dp[i+1][j+1] + 1) {
            rez.push_back(a[i]);
            ++i;
            ++j;
        } else if(dp[i+1][j] >= dp[i][j+1]) {
            ++i;
        } else {
            ++j;
        }
    }

    for(auto& i : rez)
        cout << i << ' ';

    return 0;
}