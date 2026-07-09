#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1025][1025];
short from[1025][1025];
short s1[1025], s2[1025], r[1025];


int main() {
    int n, m;
    in >> n >> m;

    for (int i = 1; i <= n; ++i)
        in >> s1[i];

    for (int i = 1; i <= m; ++i)
        in >> s2[i];

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s2[i] == s1[j]) {
                a[i][j] = a[i - 1][j - 1] + 1;
                from[i][j] = 1;
            } else {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
                from[i][j] = (a[i - 1][j] > a[i][j - 1]) ? 2 : 0;
            }
        }
    }

    out << a[m][n] << "\n";

    int i = m;
    int j = n;
    int p = 0;

    while (i > 0 && j > 0) {
        if (from[i][j] == 0) {
            j--;
        } else if (from[i][j] == 1) {
            p++;
            r[p] = s1[j];
            i--;
            j--;
        } else {
            i--;
        }
    }


    for (int i = p; i >= 1; --i)
        out << r[i] << " ";

    return 0;
}
