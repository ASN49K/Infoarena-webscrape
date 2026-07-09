#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1030], b[1030];
int d[1030][1030];

/**
 *        NULL                                         i = 0 or j = 0
 * LCS =  LCS(X(i-1), Y(i-1))                          i, j > 0 and x(i) = y(i)
 *        max(LCS(X(i), Y(i-1)), LCS(X(i-1), Y(i)))    i, j > 0 and x(i) != y(i)
 */

void read(int& n, int& m) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
}

int LCS(int n, int m) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) d[i+1][j+1] = d[i][j] + 1;
            else d[i+1][j+1] = (d[i][j+1] > d[i+1][j]) ? d[i][j+1] : d[i+1][j];
        }

    return d[n][m];
}

void write(int i, int j) {
    if (i == 0 || j == 0) return;
    if (a[i-1] == b[j-1]) {
        write(i-1, j-1);
        cout << a[i-1] << ' ';
    }
    else {
        if (d[i][j-1] > d[i-1][j]) write(i, j-1);
        else write(i-1, j);
    }
}

int main() {
    int n, m;

    read(n, m);

    cout << LCS(n, m) << '\n';
    write(n, m);

    return 0;
}