#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1024, mmax = 1024;
int a[mmax+1], b[nmax+1], dp[mmax+1][nmax+1];
// dp[i][j] = lungimea celui mai lung subsir comun pentru prefixele a[1...i] si b[1...j]
vector<int> sol;

void solve() {
    int m, n, i, j;
    fin >> m >> n;
    for (i = 1; i<=m; i++)
        fin >> a[i];
    for (i = 1; i<=n; i++)
        fin >> b[i];

    // cazuri de baza: dp[i][j] = 0 pt i = 0 sau j = 0
    for (i = 1; i<=m; i++)
        for (j = 1; j<=n; j++) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            sol.push_back(a[i]);
            i--, j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(sol.begin(), sol.end());
    fout << sol.size() << '\n';
    for (const auto &val : sol)
        fout << val << ' ';
}

int main() {
    solve();
    return 0;
}