#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main() {
    int m, n;
    in >> m >> n;
    vector <int> a(m), b(n);

    for (int i = 0; i < m; i++) {
        in >> a[i];
    }

    for (int i = 0; i < n; i++) {
        in >> b[i];
    }

    vector <vector <int> > dp(m + 1, vector <int> (n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector <int> sol;
    int l = m, c = n;
    while (l && c) {
        if (a[l - 1] == b[c - 1]) {
            sol.push_back(a[l - 1]);
            l--;
            c--;
            continue;
        }
        if (dp[l - 1][c] > dp[l][c - 1]) {
            l--;
        }
        else {
            c--;
        }
    }
    out << dp[m][n] << '\n';
    for (auto it = sol.rbegin(); it != sol.rend(); it++) {
        out << *it << ' ';
    }
    return 0;
}