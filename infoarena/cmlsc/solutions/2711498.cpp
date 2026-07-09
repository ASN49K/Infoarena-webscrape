#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nMax = 1024 + 32;

int n, m;

int a[nMax], b[nMax], mat[nMax][nMax], r[nMax];

void Citire()
{
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];

    for (int j = 1; j <= m; j++)
        fin >> b[j];

}

void Rezolvare()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }


    int i = n, j = m, k = 0;

    while (i >= 0 && j >= 0 && mat[i][j])
    {
        if (a[i] == b[j])
        {
            r[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if (mat[i - 1][j] > mat[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }

        }
    }
}

void Afisare()
{
    fout << mat[n][m] << '\n';

    for (int i = mat[n][m]; i > 0; i--)
    {
        fout << r[i] << ' ';
    }
}

int main()
{
    Citire();
    Rezolvare();
    Afisare();

    return 0;
}
