//#include "stdafx.h"
#include <iostream>
#include <fstream>

#define maxim(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, D[1030][1030], x[1030], y[1030], lcs[1030], lcsLen;

int main(int argc, char *argv[])
{
    int i, j;

    fin >> n >> m;
    for (i = 1; i <= n; ++i)
        fin >> x[i];
    for (j = 1; j <= m; ++j)
        fin >> y[j];

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (x[i] == y[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = maxim(D[i][j - 1], D[i - 1][j]);
        }
    }

    i = n;
    j = m;
    while (i)
    {
        if (x[i] == y[j])
        {
            lcs[++lcsLen] = x[i];
            --i;
            --j;
        }
        else if (D[i - 1][j] < D[i][j - 1])
            --j;
        else
            --i;
    }
    cout << lcsLen;
    i = lcsLen;
    fout << i << "\n";
    while (i)
    {
        fout << lcs[i] << " ";
        --i;
    }

    return 0;
}

