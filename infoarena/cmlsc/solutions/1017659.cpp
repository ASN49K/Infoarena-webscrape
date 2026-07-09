#include <fstream>
#include <algorithm>
#define nmax 1024+5
using namespace std;

int a[nmax], b[nmax];
int n, m;
int c[nmax][nmax];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void citire()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int j = 1; j <= m; j++)
        fin >> b[j];
}

void rezolvare()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
}

void afis_recursiv(int i, int j)
{
    if (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            afis_recursiv(i-1, j-1);
            fout << a[i] << ' ';
        }
        else
        {
            if (c[i-1][j] > c[i][j-1])
                afis_recursiv(i-1,j);
            else
                afis_recursiv(i,j-1);
        }

    }
}
void afisare()
{
    fout << c[n][m] << '\n';
    afis_recursiv(n, m);
    fout << '\n';
}
int main()
{
    citire();
    rezolvare();
    afisare();
    return 0;
}
