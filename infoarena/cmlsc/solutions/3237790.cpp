#include <bits/stdc++.h>
using namespace std;

int a[1024];
int b[1024];
int dp[1024][1024];
vector<int> ans;

int dfs(int n, int m) {
    if (n == -1 || m == -1) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (a[n] == b[m]) dp[n][m] = 1 + dfs(n-1, m-1);
    else dp[n][m] = max(dfs(n-1, m), dfs(n, m-1));
    return dp[n][m];
}

void build(int n, int m) {
    if (n == -1 || m == -1) return;
    if (a[n] == b[m]) {
        build(n-1, m-1);
        ans.push_back(a[n]);
    } else {
        if (n > 0 && (m == 0 || dp[n-1][m] >= dp[n][m-1])) {
            build(n-1, m);
        } else {
            build(n, m-1);
        }
    }
}

int main() {
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    dfs(n-1, m-1);
    cout << dp[n-1][m-1] << endl;

    build(n-1, m-1);
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
