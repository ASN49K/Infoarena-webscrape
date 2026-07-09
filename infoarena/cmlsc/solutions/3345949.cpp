#include <bits/stdc++.h>
using namespace std;

int a[1025], b[1025];
int dp[1030][1030];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef LOCAL
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
#endif

    int m, n; cin >> m >> n;
    for(int i = 1; i <= m; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[m][n] << '\n';

    vector<int> rez;
    for(int i = m, j = n; i && j; ) {
        if(a[i] == b[j] && dp[i][j] == dp[i-1][j-1] + 1) {
            rez.push_back(a[i]);
            --i;
            --j;
        } else if(dp[i-1][j] >= dp[i][j-1])
            --i;
        else
            --j;
    }

    for(int i = (int)rez.size() - 1; i >= 0; --i) {
        cout << rez[i] << ' ';
    }

    return 0;
}