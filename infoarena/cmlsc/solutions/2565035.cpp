#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#define ll long long

using namespace std;

int main() {

    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int n, m;
    in >> n >> m;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i ++)
        in >> a[i];
    vector<int> b(n + 1, 0);
    for(int i = 1; i <= m; i ++)
        in >> b[i];

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        }
    out << dp[n][m] << "\n";

    int curr = dp[n][m], fromj = m;
    vector<int> ans(dp[n][m] + 1, 0);
    for(int i = n; i >= 1; i --)
        for(int j = fromj; j >= 1; j --) {
            if(curr > 0 && curr == dp[i][j] && a[i] == b[j]) {
                ans[++ ans[0]] = a[i];
                curr --;
                fromj = j - 1;
                break;
            }
        }
    for(int i = dp[n][m]; i >= 1; i --)
        out << ans[i] << " ";

    return 0;
}
