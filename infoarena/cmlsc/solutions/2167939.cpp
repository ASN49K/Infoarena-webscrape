#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int MAXN = 1030;
int n, m, lcs[MAXN][MAXN];
int a[MAXN], b[MAXN];

void recon(int n, int m) {
    if (lcs[n][m] == 0) return;
    if (a[n] == b[m]) {
        recon(n - 1, m - 1);
        out << a[n] << " ";
    } else {
        if (lcs[n - 1][m] > lcs[n][m - 1]) {
            recon(n - 1, m);
        } else if (lcs[n][m - 1] > lcs[n - 1][m]) {
            recon(n, m - 1);
        } else {
            if (a[n] >= b[m]) {
                recon(n - 1, m);
            } else {
                recon(n, m - 1);
            }
        }
    }
}

int main()
{
    in >> n >> m;
    for (int i = 1; i <= n; ++i) in >> a[i];
    for (int i = 1; i <= m; ++i) in >> b[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    out << lcs[n][m] << "\n";
    recon(n, m);

    return 0;
}
