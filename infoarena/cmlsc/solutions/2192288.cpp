#include <iostream>
#include <fstream>
#define maxN 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[maxN], b[maxN], L[maxN][maxN], m, n;

void citire () {
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
}

int main () {
    citire();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
           if (a[i] == b[j])
                L[i][j] = L[i-1][j-1]+1;
           else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    int sol[maxN];
    int i = n, j = m, k = 0;
    while (i) {
        if (a[i] == b[j]) {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else {
            if (L[i-1][j] < L[i][j-1])
                j--;
            else
                i--;
        }
    }
    fout << k << '\n';
    for (int i = k; i >= 1; --i) {
        fout << sol[i]<< " ";
    }
}
