#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("cmlsc.in");ofstream cout("cmlsc.out");
//ifstream cin("input");ofstream cout("output");

int v1[1030];
int v2[1030];
int dp[1030][1030];

void afisare_nr(int i, int j) {
    if (i < 1 || j < 1) {
        return;
    }
    if (dp[i - 1][j - 1] == dp[i][j] - 1) {
        afisare_nr(i - 1, j - 1);
        cout << v1[i] << " ";
        return;
    }
    if (dp[i - 1][j] == dp[i][j]) {
        afisare_nr(i - 1, j);
        return;
    }
    if (dp[i][j - 1] == dp[i][j]) {
        afisare_nr(i, j - 1);
        return;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> v2[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<'\n';
    }
    cout << dp[n][m] << '\n';
    afisare_nr(n, m);
    return 0;
}