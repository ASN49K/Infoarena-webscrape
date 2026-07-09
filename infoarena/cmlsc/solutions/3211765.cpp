#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int dim = 1025;

int a[dim], b[dim];
int d[dim][dim];

void afisare(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }

    if (a[i] == b[j]) {
        afisare(i - 1, j - 1);
        out << a[i] << " ";
        return;
    }

    if (d[i - 1][j] > d[i][j - 1]) {
        afisare(i - 1, j);
    } else {
        afisare(i, j - 1);
    }
}

int main()
{
    int n, m, i, j;

    in >> n >> m;

    for (i = 1; i <= n; i++) {
        in >> a[i];
    }

    for (i = 1; i <= m; i++) {
        in >> b[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                d[i][j] = 1 + d[i - 1][j - 1];
            } else {
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);
            }
        }
    }

    // for (i = 1; i <= n; i++) {
    //     for (j = 1; j <= m; j++) {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    out << d[n][m] << "\n";
    afisare(n, m);

    in.close();
    out.close();

    return 0;
}