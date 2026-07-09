#include <fstream>
#include <vector>
#define nmax 1025
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[nmax], b[nmax], n, m, ma[nmax][nmax];
int sol[nmax], k, i, j;


int main ()
{
    fin >> n >> m;
    for (i = 1; i <= n; i++) fin >> a[i];
    for (i = 1; i <= m; i++) fin >> b[i];

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                ma[i][j] = ma[i - 1][j - 1] + 1;
            else
            {
                ma[i][j] = max (ma[i - 1][j], ma[i][j - 1]);
            }
        }
    }
    fout << ma[n][m] << "\n";

    i = n;
    j = m;
    k = 0;
    while (i && j)
    {
        if (a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else
        {
            if (ma[i - 1][j] > ma[i][j - 1]) i--;
            else j--;
        }

    }
    for (i = k; i > 0; i--)
        fout << sol[i] << " ";

    return 0;
}

