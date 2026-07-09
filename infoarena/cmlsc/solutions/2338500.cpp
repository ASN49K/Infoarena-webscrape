#include <iostream>
#include <fstream>
using namespace std;

#define NMax 1024

int d[NMax][NMax], sir[NMax], bst;

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int m, n;
    fin >> m >> n;

    int a[NMax], b[NMax];
    for (int i = 1; i <= m; ++i)
        fin >> a[i];
    for (int i = 1; i <= n; ++i)
        fin >> b[i];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);

    for (int i = m, j = n; i;)
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else
        if (d[i - 1][j] < d[i][j - 1])
            --j;
        else
            --i;

    fout << bst << '\n';
    for (int i = bst; i; --i)
        fout << sir[i] << " ";

    return 0;
}
