#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1030;

int n, m;

int a[nmax], b[nmax], l[nmax][nmax];

void Afis(int i, int j)
{
    if (!l[i][j])
        return;

    if (a[i] == b[j])
    {
        Afis(i - 1, j - 1);
        fout << a[i] << ' ';
    }
    else
    {
        if (l[i - 1][j] > l[i][j - 1])
            Afis(i - 1, j);
        else
            Afis(i, j - 1);
    }
}

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];

    for (int j = 1; j <= m; j++)
        fin >> b[j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);

    fout << l[n][m] << '\n';

    Afis(n, m);

    fin.close();
    fout.close();
    return 0;
}

