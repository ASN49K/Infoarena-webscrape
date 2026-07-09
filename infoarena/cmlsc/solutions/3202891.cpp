#include <bits/stdc++.h>
#define MAXN 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[MAXN], b[MAXN], dp[MAXN][MAXN];

void show(int i, int j, int val) {
    if (!i || !j)
        return;

    if (dp[i - 1][j] == val)
        show(i - 1, j, val);
    else if (dp[i][j - 1] == val)
        show(i, j - 1, val);
    else {
        show(i - 1, j - 1, dp[i - 1][j - 1]);
        fout << a[i] << ' ';
    }
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    fout << dp[n][m] << '\n';
    show(n, m, dp[n][m]);
    return 0;
}
