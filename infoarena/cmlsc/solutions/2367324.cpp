#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & -x)

using namespace std;

ifstream in("a.in");
ofstream out("a.out");


int main() {

    int n, m;
    in >> n >> m;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i ++)
        in >> a[i];
    vector<int> b(m + 1, 0);
    for(int i = 1; i <= m; i ++)
        in >> b[i];

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    vector<vector<pair<int, int>>> from(n + 1, vector<pair<int, int>> (m + 1, {0, 0}));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                from[i][j] = {i - 1, j - 1};
            }

            if(dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                from[i][j] = {i - 1, j};
            }
            if(dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                from[i][j] = {i, j - 1};
            }
        }
    out << dp[n][m] << "\n";
    int i = n, j = m;
    vector<int> sol;
    while(i != 0 && j != 0) {
        auto x = from[i][j];
        if(i - x.first == 1 && j - x.second == 1)
            sol.push_back(a[i]);
        i = x.first;
        j = x.second;
    }
    reverse(sol.begin(), sol.end());
    for(auto it : sol)
        out << it << " ";

    return 0;
}
