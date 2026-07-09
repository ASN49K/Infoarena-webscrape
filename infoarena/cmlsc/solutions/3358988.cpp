#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; cin >> a[i ++]);
    int b[m];
    for(int i = 0; i < m; cin >> b[i ++]);
    int dp[n + 1][m + 1] = {};
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i - 1] == b[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int c[n];
    int k = 0;
    for(int i = n, j = m; dp[i][j]; ) {
        if(dp[i - 1][j - 1] + 1 == dp[i][j]) {
            c[k ++] = a[i - 1];
            i --; j --;
            continue;
        }
        if(dp[i][j] == dp[i - 1][j]) {
            i --;
            continue;
        }
        j --;
    }
    cout << k << '\n';
    assert(k == dp[n][m]);
    reverse(c, c + k);
    for(int i = 0; i < k; i ++) {
        cout << c[i] << ' ';
    }
}