#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v[1030], w[1030], D[1030][1030];

void afis(int n, int m) {
    if (n == 0 || m == 0) {
        return;
    }
    if (v[n] == w[m]) {
        afis(n - 1, m);
        fout << v[n] << " ";
    } else {
        if (D[n - 1][m] > D[n][m - 1]) {
            afis(n - 1, m);
        } else {
            afis(n, m - 1);
        }
    }
}

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fin >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i] == w[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            } else {
                D[i][j] = max(D[i][j - 1], D[i - 1][j]);
            }
        }
    }
    fout << D[n][m] << "\n";
    afis(n, m);
    return 0;
}