#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 1107;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
vector < int > ans;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int j = 1; j <= m; ++j) {
        cin >> b[j];
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    while(i >= 1 && j >= 1) {
        if(a[i] == b[j]) {
            ans.push_back(a[i]);
            --i;
            --j;
        }
        else {
            if(dp[i][j - 1] > dp[i - 1][j]) {
                --j;
            }
            else {
                --i;
            }
        }
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
