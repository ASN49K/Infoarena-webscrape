#include <fstream>
#include <iostream>
#include <vector>

#pragma GCC optimize("O3")
#pragma GCC optimization("Ofast,unroll-loops")

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define in fin
#define out fout
#define int long long

signed main() {
    int n, m;
    in >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        in >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        in >> b[i];
    }
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    out << dp[n][m] << "\n";
    int ant = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][m] > ant) {
            ant++;
            out << a[i] << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
