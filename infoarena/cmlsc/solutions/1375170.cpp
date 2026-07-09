#include <fstream>

using namespace std;

short v[1026], w[1026], sol[1026];
short a[1026][1026];
short d[1026][1026];    // 1 - diag, 2 - sus, 3 - stanga

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int n, m;
    in >> n >> m;

    for (int i = 1; i <= n; i++)
        in >> v[i];
    for (int j = 1; j <= n; j++)
        in >> w[j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i] == w[j])
            {
                a[i][j] = a[i-1][j-1] + 1;
                d[i][j] = 1;
            }
            else
            {
                if (a[i-1][j] > a[i][j-1])
                {
                    a[i][j] = a[i-1][j];
                    d[i][j] = 2;
                }
                else
                {
                    a[i][j] = a[i][j-1];
                    d[i][j] = 3;
                }
            }
        }
    }

    out << a[n][m] << '\n';

    int x = n;
    int y = m;

    int nrs = 0;
    while (d[x][y])
    {
        if (d[x][y] == 1)
        {
            sol[++nrs] = v[x];
            x--;
            y--;
        }
        else
        {
            if (d[x][y] == 2)
                x--;
            else
                y--;
        }

    }

    out << sol[nrs];
    for (int i = nrs-1; i > 0; i--)
        out << ' ' << sol[i];
    out << '\n';

    return 0;
}
