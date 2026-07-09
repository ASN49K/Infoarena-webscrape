#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> LCS(const vector<int> &a, const vector<int> &b) {
    const int n = a.size(); 
    const int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    vector<int> seq;
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if (a[i - 1] == b[j - 1]) {
            seq.push_back(a[i - 1]);
            --i;
            --j;
        } else if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else if (dp[i][j] == dp[i][j - 1]) {
            --j;
        }
    }
    reverse(seq.begin(), seq.end());
    return seq;
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    vector<int> ans = LCS(a, b);
    cout << ans.size() << '\n';
    for (int &x : ans)
        cout << x << ' ';
}