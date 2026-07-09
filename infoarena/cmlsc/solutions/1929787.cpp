#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int lcs[1030][1030];
int a[1030], b[1030];
int v[1030];

int main()
{
    int n, m, i, j;
    fin >> n >> m;

    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }

    fout << lcs[n][m] << '\n';

    int k = 1;
    while (i && j)
    {
        if (lcs[i][j] == 1 + lcs[i - 1][j - 1])
        {
            v[k++] = a[i];
            i--; j--;
        }
        else
        {
            if (lcs[i][j - 1] > lcs[i - 1][j])
                j--;
            else
                i--;
        }
    }

    for (k--; k; k--)
        fout << v[k] << ' ';
    fout << '\n';
    return 0;
}
