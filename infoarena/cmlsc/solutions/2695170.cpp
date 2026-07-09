#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int maxim(int a, int b) {
    return (a < b) ? b : a;
}
int main() {
    int n, m;
    fin >> n >> m;
    int x[1030], y[1030], b[1030][1030];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            b[i][j] = 0;
    for (int i = 1; i <= n; i++)
        fin >> x[i];
    for (int i = 1; i <= m; i++)
        fin >> y[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (x[i] == y[j])
                b[i][j] = b[i - 1][j - 1] + 1;
            else
                b[i][j] = maxim(b[i - 1][j], b[i][j - 1]);

    fout << b[n][m];

    int s = b[n][m];
    int sol[1030];
    int i = n, j = m;
    while (s != 0) {
        if (x[i] == y[j])
            sol[s] = x[i], i--, j--, s--;
        else
            if (b[i][j - 1] < b[i - 1][j])
                i--; else
                j--;
    }

    fout << '\n';
    for (i  = 1; i <= b[n][m]; i++)
        fout << sol[i] << ' ';
}
