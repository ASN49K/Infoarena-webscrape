#include <bits/stdc++.h>
using namespace std;
#define x1 "cmlsc.in"
#define x2 "cmlsc.out"
ifstream in(x1);
ofstream out(x2);
#define NMAX 1025
int dp[NMAX][NMAX], v1[NMAX], v2[NMAX], ans[NMAX];
int main() {
    int n, m, i, j, maxi;
    in >> n >> m;
    for(i = 1; i <= n; i++)
        in >> v1[i];
    for(i = 1; i <= m; i++)
        in >> v2[i];
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            if(v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    i = n;
    j = m;
    maxi = dp[n][m];
    while (maxi > 0) {
        if (dp[i - 1][j] == maxi)
            --i;
        else if (dp[i][j - 1] == maxi)
            --j;
        else {
            ans[--maxi] = v1[i--];
            j--;
        }
    }
    out << dp[n][m] << "\n";
    for (i = 0; i < dp[n][m]; ++i)
        out << ans[i] << " ";
}
