#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int L[1025][1025], b[2000], a[2000], rez[1025];

int n, m;

void afisare()
{
    int dr = 0;
    int i, j;
    i = n;
    j = m;
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            dr++;
            rez[dr] = a[i];
        }
        if (L[i][j - 1] < L[i - 1][j])
            i--;
        else
            j--;
    }

    for (i = dr; i >= 1; i--)
        fout << rez[i] << ' ';
}

int main()
{

    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                L[i][j] = 1 + L[i - 1][j - 1];
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    fout << L[n][m] << '\n';
    afisare();
    return 0;
}
