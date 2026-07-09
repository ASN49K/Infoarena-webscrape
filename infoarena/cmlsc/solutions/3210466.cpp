#include <bits/stdc++.h>

using namespace std;

ifstream in("liceu.in");
ofstream out("liceu.out");

const int maxn = 2e3 + 5;

int v[maxn], w[maxn];

int dp[maxn][maxn];

int sol[maxn];

int main() {

    int n, m;

    in >> n >> m;

    for (int i(1); i <= n; i++) {
        in >> v[i];
    }

    for (int i(1); i <= m; i++) {
        in >> w[i];
    }

    for (int i(1); i <= n; i++) {
        for (int j(1); j <= m; j++) {
            if (v[i] == w[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int x = n;
    int y = m;

    while (x > 0 && y > 0) {
        if (v[x] == w[y]) {
            sol[++sol[0]] = v[x];
            x--;
            y--;
        } else if (dp[x - 1][y] >= dp[x][y - 1]) {
            x--;
        } else {
            y--;
        }
    }

    out << sol[0] << '\n';

    for (int i(sol[0]); i > 0; i--) {
        out << sol[i] << ' ';
    }

    return 0;
}