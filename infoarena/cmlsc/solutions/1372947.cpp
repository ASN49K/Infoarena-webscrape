#include <iostream>
#include <fstream>
using namespace std;

const int kNMax = 1050;
int n, m, v1[kNMax], v2[kNMax], dp[kNMax][kNMax];
int sol, cmlsc[kNMax];

void Citire() {
    ifstream in ("cmlsc.in");
    in >> n >> m;
    for (int i = 1; i <= n; ++i)
        in >> v1[i];
    for (int i = 1; i <= m; ++i)
        in >> v2[i];
    in.close();
}

void Solve() {
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            if (v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    i = n;
    j = m;
    while (i)
        if (v1[i] == v2[j]) {
            cmlsc[++sol] = v1[i];
            i--;
            j--;
        } else
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
}

void Afisare() {
    ofstream out("cmlsc.out");
    out << sol << '\n';
    for (int i = sol; i >= 1; --i)
        out << cmlsc[i] << ' ';
    out.close();
}

int main () {
    Citire();
    Solve();
    Afisare();
    return 0;
}
