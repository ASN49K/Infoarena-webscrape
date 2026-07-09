#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define PLEC fin.close(); fout.close(); return 0;
using namespace std;
const string problem("nim");
ifstream fin(problem + ".in");
ofstream fout(problem + ".out");
int t, n, x, nim;
int main() {
    DAU
    fin >> t;
    while (t--) {
        fin >> n;
        nim = 0;
        for (int i = 1; i <= n; ++i) {
            fin >> x;
            nim ^= x;
        }
        if (nim)
            fout << "DA\n";
        else fout << "NU\n";
    }
    PLEC
}
