#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXN = 1e3;
int a[MAXN + 50], b[MAXN + 50], matrix[MAXN + 50][MAXN + 50], n, m;

void read() {
    fin >> n >> m;
    for (int i = 0; i < n; ++i)
        fin >> a[i];
    for (int i = 0; i < m; ++i)
        fin >> b[i];
}

void solve() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            if (a[i] == b[j])
                matrix[i][j] = max(matrix[i][j], matrix[i - 1][j - 1] + 1);
        }
}

int main() {
    read();
    solve();
    fout << matrix[n][m];
    return 0;
}
