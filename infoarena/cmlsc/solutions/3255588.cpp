#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[1025][1025];
int v1[1025], v2[1025];
stack<int> ans;

void backtrack(int i, int j) {
    while (dp[i][j] != 0) {
        if (v1[i] == v2[j]) {
            ans.push(v1[i]);
            --i;
            --j;
        } else if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else {
            --j;
        }
    }
}

int main() {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> v1[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> v2[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v1[i] == v2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    backtrack(n, m);
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}
