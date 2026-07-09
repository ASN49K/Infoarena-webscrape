#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    int m, n, i, j, k;
    int a[1024], b[1024], c[1024][1024] = {0}, sir[1024];
    int x = 0;

    fin >> m >> n;

    for (i = 1; i <= m; i++)
        fin >> a[i];

    for (i = 1; i <= n; i++)
        fin >> b[i];

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
            {
                if (c[i - 1][j] > c[i][j - 1])
                    c[i][j] = c[i - 1][j];
                else
                    c[i][j] = c[i][j - 1];
            }
        }

    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            sir[++x] = a[i];
            i--;
            j--;
        }
        else if (c[i - 1][j] < c[i][j - 1])
            j--;
        else
            i--;
    }

    fout << x << '\n';
    for (k = x; k >= 1; k--)
        fout << sir[k] << ' ';
}
