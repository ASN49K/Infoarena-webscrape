#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int nMax = 1026;
int dp[nMax][nMax];
int a[nMax], b[nMax];
inline void Afis(int x, int y) {
    if(x != 0 && y != 0) {
        if(a[x] == b[y]) {
            Afis(x - 1, y - 1);
            g << a[x] << " ";
        }
        else {
            if(dp[x][y - 1] > dp[x - 1][y]) {
                Afis(x, y - 1);
            }
            else {
                Afis(x - 1, y);
            }
        }
    }
}
int main()
{
    int n, m;
    f >> n >> m;
    for(int i = 1; i <= n; i++) {
        f >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        f >> b[i];
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
    g << dp[n][m] << "\n";
    Afis(n , m);
    return 0;
}
