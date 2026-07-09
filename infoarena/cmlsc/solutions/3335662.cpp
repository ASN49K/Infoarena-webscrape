//https://www.infoarena.ro/problema/cmlsc
#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NRMAX = 1024;

int a[NRMAX + 1], b[NRMAX + 1], rez[NRMAX + 1];
int d[NRMAX + 1][NRMAX + 1];

int main()
{
    int n, m, i, j, k;

    fin >> n >> m;
    for (i = 1; i <= n; ++i)
        fin >> a[i];
    for (i = 1; i <= m; ++i)
        fin >> b[i];

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);
        }
    }

    fout << d[n][m] << "\n";

//    for (i = 1; i <= n; ++i)
//    {
//        for (j = 1; j <= m; ++j)
//        {
//            cout << d[i][j] << " ";
//        }
//        cout << "\n";
//    }

    i = n;
    j = m;
    k = 0;
    while (i >= 1 && j >= 1)
    {
        //cout << i << " " << j << "\n";
        //cout << a[i] << "\n";
        if (a[i] == b[j])
            rez[k++] = a[i--], --j;
        else if (d[i - 1][j] > d[i][j - 1])
            --i;
        else
            --j;
    }

    //cout << k << " ";
    for (i = k - 1; i >= 0; --i)
        fout << rez[i] << " ";

    return 0;
}
