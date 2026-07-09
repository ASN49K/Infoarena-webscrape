#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int N_MAX = 1029;

int n, m, a[N_MAX], b[N_MAX], dp[N_MAX][N_MAX], c[N_MAX], p;

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[n][m] << "\n";
    int i = n, j = m;
    while (i != 0 && j != 0) {
        if (a[i] == b[j]) {
            c[++p] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    for (int i = p; i >= 1; i--)
        fout << c[i] << " ";
    fout << "\n";
    return 0;
}
