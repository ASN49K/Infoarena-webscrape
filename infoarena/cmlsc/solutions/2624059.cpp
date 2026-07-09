#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short unsigned a[2030][2030];
int i, j, n, m, x[2030], y[2030];
void Formare()
{
    for (i = 1; i <= n; i ++)
    {
        for (j = 1; j <= m; j ++)
        {
            if (x[i] == y[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
    }
}
void Raspuns(int n, int m)
{
    if (n != 0 and m != 0)
    {
        if (x[n] == y[m])
        {
            Raspuns(n - 1, m - 1);
            fout << x[n] << " ";
        }
        else
        {
            if (a[n - 1][m] > a[n][m - 1])
                Raspuns(n - 1, m);
            else
                Raspuns(n, m - 1);
        }
    }
}
int main()
{
    fin >> n >> m;
    for (i = 1; i <= n; i ++)
        fin >> x[i];
    for (i = 1; i <= m ; i ++)
        fin >> y[i];
    Formare();
    fout << a[n][m] << "\n";
    Raspuns(n, m);
    return 0;
}
