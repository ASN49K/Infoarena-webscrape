#define MAX_DIM 2048

#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n1, n2, sir1[MAX_DIM + 1], sir2[MAX_DIM + 1], a[MAX_DIM + 1][MAX_DIM + 1];

void Afisare(int x, int y);

int main()
{
    fin >> n1 >> n2;
    for (int i = 1; i <= n1; ++i)
    { fin >> sir1[i]; }
    for (int i = 1; i <= n2; ++i)
    { fin >> sir2[i]; }

    for(int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j)
        {
            if (sir1[i] == sir2[j])
            { a[i][j] = a[i - 1][j - 1] + 1; }
            else
            { a[i][j] = max(a[i - 1][j], a[i][j - 1]); }
        }
    }

    fout << a[n1][n2] << '\n';
    Afisare(n1, n2);

    fin.close();
    fout.close();
    return 0;
}

void Afisare(int x, int y)
{
    if ((x == 0) || (y == 0)) { return; }

    while (a[x][y - 1] == a[x][y]) { --y; }
    while (a[x - 1][y] == a[x][y]) { --x; }

    Afisare(x - 1, y - 1);
    fout << sir1[x] << ' ';
}
