/*
 Lefter Sergiu - 11/01/2023
*/
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1024;

int a[N+1], b[N+1], dp[N+1][N+1], n, m;

void refacSubsir(int l, int c) {
    if (l == 0 || c == 0) {
        return;
    }
    if (a[l] == b[c]) {
        refacSubsir(l - 1, c - 1);
        out << a[l] << " ";
    }
    else {
        if (dp[l-1][c] > dp[l][c-1]) {
            refacSubsir(l - 1, c);
        }
        else {
            refacSubsir(l, c - 1);
        }
    }
}

int main() {
    in >> n >> m;
    for (int i = 1; i <= n; ++i) {
        in >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        in >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    out << dp[n][m] << '\n';
    refacSubsir(n, m);
    in.close();
    out.close();
    return 0;
}