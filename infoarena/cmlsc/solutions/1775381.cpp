#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int nmax = 1030;
int v[nmax], w[nmax], sol[nmax], dp[nmax][nmax], lg;

int main() {
    ios_base :: sync_with_stdio(false);
    int n, m, i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++) {
        fin >> v[i];
    }
    for (i = 1; i <= m; i++) {
        fin >> w[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (v[i] == w[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    i = n, j = m;
    while (i && j) {
        if (v[i] == w[j]) {
            sol[++lg] = v[i];
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    fout << lg << "\n";
    for (i = lg; i; i--) {
        fout << sol[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
