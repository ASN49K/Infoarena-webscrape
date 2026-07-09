#include <bits/stdc++.h>
using namespace std;

#define C 1025

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short m, n, a[C], b[C], dp[C][C];
vector<short> v;

void fincmlsc() {
    for (short i = 1; i < m + 1; i++)
        for (short j = 1; j < n + 1; j++)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void recon(short i, short j) {
    if (i < 1 || j < 1)
        return;

    if (a[i - 1] == b[j - 1]) {
        v.push_back(a[i - 1]);
        return recon(i - 1, j - 1);
    }
    if (dp[i][j - 1] > dp[i - 1][j])
        return recon(i, j - 1);
    return recon(i - 1, j);
}

int main() {
    f >> m >> n;
    for (short i = 0; i < m; i++)
        f >> a[i];
    for (short i = 0; i < n; i++)
        f >> b[i];

    fincmlsc();
    recon(m, n);
    g << dp[m][n] << "\n";
    for (short i = v.size() - 1; i >= 0; i--)
        g << v[i] << " ";
    return 0;
}