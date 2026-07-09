#include <bits/stdc++.h>

#define NMAX 1030
#define f cin
#define g cout

using namespace std;

//ifstream f("cmlsc.in");
//ofstream g("cmlsc.out");

int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX];

int main() {
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        f >> a[i];
    for (int i = 1; i <= m; i++)
        f >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    g << dp[n][m];

    int i = n, j = m;
    int sol[NMAX], k = dp[n][m];
    while (i && j) {
        if (dp[i][j] > dp[i-1][j-1])
            sol[k--] = a[i], i--, j--;
        else {
            if (dp[i][j-1] > dp[i-1][j]) j--;
            else i--;
        }
    }

    g << '\n';
    for (int i=1; i<=dp[n][m]; i++)
        g << sol[i] << ' ';
}
