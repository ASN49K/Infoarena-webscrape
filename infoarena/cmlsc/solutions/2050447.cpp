#include <fstream>
#define NMAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, a[NMAX], b[NMAX], lg[NMAX][NMAX], urm[NMAX][NMAX];

int main()
{
    int i, j;
    fin >> m >> n;
    for (i = 1; i <= m; i++)
        fin >> a[i];
    for (i = 1; i <= n; i++)
        fin >> b[i];
    for (i = m; i >= 1; i--)
    {
        for (j = n; j >= 1; j--)
        {
            if (a[i] == b[j])
            {
                lg[i][j] = lg[i + 1][j + 1] + 1;
                urm[i][j] = 3;
            }
            else
            {
                if (lg[i][j + 1] > lg[i + 1][j])
                {
                    lg[i][j] = lg[i][j + 1];
                    urm[i][j] = 2;
                }
                else
                {
                    lg[i][j] = lg[i + 1][j];
                    urm[i][j] = 1;
                }
            }
        }
    }
    fout << lg[1][1] << '\n';
    for (i = 1, j = 1; urm[i][j]; )
    {
        if (urm[i][j] == 1)
            i++;
        else if (urm[i][j] == 2)
            j++;
        else
        {
            fout << a[i] << ' ';
            i++;
            j++;
        }
    }
    fout << '\n';
    fout.close();
    return 0;
}
