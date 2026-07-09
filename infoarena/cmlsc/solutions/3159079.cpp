#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1025], b[1025];
int c[1025][1025];
int rez[1025];

int main() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                c[i][j] = 1 + c[i - 1][j - 1];
            } else {
                c[i][j] = max(c[i - 1][j - 1], max(c[i][j - 1], c[i - 1][j - 1]));
            }
        }
    }
    int l = 0;
    for (int i = n, j = m; i && j;) {
        if (a[i] == b[j]) {
            rez[l++] = a[i];
            i--;
            j--;
        } else if (c[i - 1][j] > c[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    fout << l << "\n";
    for (int i = 0; i < l; i++) {
        fout << rez[i] << " ";
    }
}
