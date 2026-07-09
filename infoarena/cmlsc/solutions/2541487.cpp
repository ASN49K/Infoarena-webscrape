#include <iostream>
using namespace std;

#define fisier "cmlsc"
#ifdef fisier
    #include <fstream>
    ifstream in(fisier ".in");
    ofstream out(fisier ".out");
#else
    #define in cin
    #define out cout
#endif



int n, m, a[1 << 10], b[1 << 10], d[(1 << 10) + 1][(1 << 10) + 1];



void cmlsc(int sfr_a, int sfr_b) {

    if (!sfr_a || !sfr_b)
        return;

    if (a[sfr_a - 1] == b[sfr_b - 1]) {

        cmlsc(sfr_a - 1, sfr_b - 1);

        out << a[sfr_a - 1] << ' '; // b[sfr_b - 1];

    } else {

        if (d[sfr_a - 1][sfr_b] < d[sfr_a][sfr_b - 1]) {

            cmlsc(sfr_a, sfr_b - 1);

        } else {

            cmlsc(sfr_a - 1, sfr_b);

        }

    }

}



int main() {

    in >> n >> m;

    int i, j;

    for (i = 0; i < n; i++)
        in >> a[i];

    for (i = 0; i < m; i++)
        in >> b[i];



    for (i = 1; i <= n; i++) {

        for (j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1]) {

                d[i][j] = d[i - 1][j - 1] + 1;

            } else {

                d[i][j] = max(d[i - 1][j], d[i][j - 1]);

            }

        }

    }



    out << d[n][m] << '\n';

    cmlsc(n, m);

}
