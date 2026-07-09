#include <iostream>
#include <fstream>
#define NMAX 1024
using namespace std;

ifstream fin;
ofstream fout;

int a[NMAX], b[NMAX], T[NMAX][NMAX], m, n, sirMaxim[NMAX], lungimeMaxima, i, j;

int max(int a, int b) {
    if (a>b)
        return a;
    else return b;
}

int main()
{
    fin.open("cmlsc.in");
    fout.open("cmlsc.out");
    fin >> m >> n;

    for (i = 0; i < m; i++) {
        fin >> a[i];
    }

    for (i = 0; i < n; i++) {
        fin >> b[i];
    }

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i] == b[j]) {
                T[i][j] = 1 + T[i-1][j-1];
            } else {
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
    }

    i = m, j = n;

    while (i) {
        if (T[i][j] == T[i-1][j]) {
            i--;
        } else if (T[i][j] == T[i][j-1]) {
            j--;
        } else {
            sirMaxim[lungimeMaxima++] = a[i];
            i--;
            j--;
        }
    }

    fout<<lungimeMaxima<<"\n";
    for (i = 0; i < lungimeMaxima; i++) {
        fout<<sirMaxim[i]<<' ';
    }

    fin.close();
    fout.close();
    return 0;
}
