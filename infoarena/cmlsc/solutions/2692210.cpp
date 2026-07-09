#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int L[1025][1025], b[2000], a[2000], unu, doi;

int main()
{
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j] && unu == 0)
                L[i][j] = 1 + L[i - 1][j - 1], unu = a[i];
            else if (a[i] == b[j])
                L[i][j] = 1 + L[i - 1][j - 1], doi = a[i];
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    fout << L[n][m] << '\n'
         << unu << ' ' << doi;
    return 0;
}
