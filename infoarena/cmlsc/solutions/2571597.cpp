#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1030;

int n, m;

int a[nmax], b[nmax], c[nmax][nmax], v[nmax];

stack < int, vector<int> > stk;

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];

    for (int i = 1; i <= m; i++)
        fin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);

    fout << c[n][m] << '\n';

    int i = n, j = m, k = 0;

    while (i >= 0 && j >= 0 && c[i][j])
    {
        if (a[i] == b[j])
        {
            v[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if (c[i - 1][j] > c[i][j - 1])
                i--;
            else
                j--;
        }
    }

    for (int i = k; i > 0; i--)
        fout << v[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
