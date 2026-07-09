#include <bits/stdc++.h>
#define MAXSZ 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[MAXSZ + 1], b[MAXSZ + 1], dp[MAXSZ + 1][MAXSZ + 1];

void show(int i = n, int j = m) {
    if (i == 0 || j == 0)
        return;
    if (dp[i - 1][j] > dp[i][j - 1])
        show(i - 1, j);
    else
        show(i, j - 1);
    if (a[i] == b[j])
        fout << a[i] << ' ';
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    fout << dp[n][m] << '\n';
    show();
    return 0;
}
