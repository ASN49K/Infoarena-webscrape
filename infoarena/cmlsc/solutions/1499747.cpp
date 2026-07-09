#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1050], b[1050], v[1050][1050];
int n, m;
int t;
int c[1050];
int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        fin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                v[i][j] = 1 + v[i - 1][j - 1];
            }
            else {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    for (int i = n, j = m; i; ) {
        if (a[i] == b[j]) {
            c[++t] = a[i];
            --i;
            --j;
        }
        else if (v[i - 1][j] < v[i][j - 1]) {
            --j;
        }
        else {
            --i;
        }
    }
    fout << t << '\n';
    for (int i = t; i >= 1; --i) {
        fout << c[i] << ' ';
    }
    fout.close();
    return 0;
}

