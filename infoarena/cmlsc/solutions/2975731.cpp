#include <bits/stdc++.h>
#define MAXN 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[MAXN + 1], b[MAXN + 1], dp[MAXN + 1][MAXN + 1];
void show(int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (a[i] == b[j]) {
        show(i - 1, j - 1);
        fout << a[i] << ' ';
        return;
    }
    if (dp[i][j - 1] > dp[i - 1][j]) {
        show(i, j - 1);
        return;
    }
    show(i - 1, j);
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
    show(n, m);
    return 0;
}