#include <fstream>

#define MAXL 1030
#define L 0
#define U 1
#define DI 2

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int main()
{
    int n, m, a[MAXL], b[MAXL];
    int i, j;

    f >> n >> m;

    int v[n + 1][m + 1][2];

    for (i = 1; i <= n; v[i][0][0] = 0, f >> a[i++]);
    for (i = 1; i <= m; v[0][i][0] = 0, f >> b[i++]);
    v[0][0][0] = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                v[i][j][0] = v[i - 1][j - 1][0] + 1;
                v[i][j][1] = DI;
            }
            else
            {
                if (v[i - 1][j][0] == v[i][j - 1][0])
                {
                    v[i][j][0] = v[i - 1][j][0];

                    if (v[i - 1][j][0] == 0)
                        v[i][j][1] = L;
                    else
                        v[i][j][1] = U;
                }
                else if (v[i - 1][j][0] < v[i][j - 1][0])
                {
                    v[i][j][0] = v[i][j - 1][0];
                    v[i][j][1] = U;
                }
                else
                {
                    v[i][j][0] = v[i - 1][j][0];
                    v[i][j][1] = L;
                }
            }
        }
    }

    g << v[n][m][0] << "\n";

    i = n;
    j = m;

    int sol[MAXL], c = 0;

    while (i && j)
    {
        switch (v[i][j][1])
        {
        case L:
            {
                i--;
            } break;
        case U:
            {
                j--;
            } break;
        case DI:
            {
                sol[c++] = a[i];
                i--;
                j--;
            } break;
        default:
            {

            } break;
        }
    }

    for (--c; c >= 0; g << sol[c--] << " ");

    f.close();
    g.close();

    return 0;
}
