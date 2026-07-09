#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define fs first
#define sd second

using namespace std;

const string fileName = "cmlsc";
ifstream in(fileName + ".in");
ofstream out(fileName + ".out");

int n, m, a[2005], b[2005];
int dp[2005][2005];

signed main() {
    in >> n >> m;
    for(int i = 1; i <= n; i++) {
        in >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        in >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    vector<int> ans;
    for(int i = n, j = m; i >= 1 && j >= 1; ) {
        if(a[i] == b[j]) {
            ans.push_back(a[i]);
            i--; j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());
    out << ans.size() << '\n';
    for(auto elem : ans) {
        out << elem << ' ';
    }
    out << '\n';
    return 0;
}
