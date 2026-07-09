#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[1030], b[1030], d[1030][1030];

void citire() {
    f >> m >> n;
    for (int i = 1; i <= m; ++i)
        f >> a[i];
    for (int i = 1; i <= n; ++i)
        f >> b[i];
}

void creare_matrice() {
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
}

void afis(int lin, int col) {
    if (!d[lin][col])
        return;
    if (a[lin] == b[col]) {
        afis(lin - 1, col - 1);
        g << a[lin] << ' ';
        return;
    }
    if (d[lin - 1][col] > d[lin][col - 1])
        afis(lin - 1, col);
    else
        afis(lin, col - 1);
}

void afisare() {
    g << d[m][n] << '\n';
    afis(m, n);
}

int main() {
    citire();
    creare_matrice();
    afisare();
    return 0;
}
