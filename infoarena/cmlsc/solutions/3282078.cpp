#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, i, j;
int dp[1025][1025];
int v[1025], x[1025];
vector < int > sol;

int main() {
    cin >> n >> m;
    for(i = 1; i <= n; ++i)
        cin >> v[i];
    for(i = 1; i <= m; ++i)
        cin >> x[i];
    for(i = 1; i <= n; ++i)
    for(j = 1; j <= m; ++j) {
        if(v[i] == x[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
            sol.push_back(v[i]);
        }
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    cout << dp[n][m] << '\n';


    for(auto i : sol)
        cout << i << " ";

    return 0;
}
