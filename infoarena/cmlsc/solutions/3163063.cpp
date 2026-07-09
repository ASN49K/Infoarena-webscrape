// basic file operations
#include <iostream>
#include <fstream>
using namespace std;
#define NMax 1025

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[NMax], b[NMax], d[NMax][NMax], sir[NMax], best;

int main()
{
    int i, j;

    fin >> m >> n;

    for (i = 1; i <= m; i++)
        fin >> a[i];

    for (i = 1; i <= n; i++)
        fin >> b[i];

    for (i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);

    for (i = m, j = n; i;)
        if (a[i] == b[j])
            sir[++best] = a[i], --i, --j;
        else if (d[i - 1][j] < d[i][j - 1])
            --j;
        else
            --i;

    fout << best << "\n";
    for (i = best; i; i--)
        fout << sir[i] << " ";

    fin.close();
    fout.close();
}