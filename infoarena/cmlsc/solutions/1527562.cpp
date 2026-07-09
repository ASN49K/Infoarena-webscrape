#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m;
int i, j, k;
int a[1025], b[1025], c[1025][1025];
int rez[1025];

int main()
{
    f >> n >> m;
    for (i = 1; i <= n; i++)
        f >> a[i];
    for (i = 1; i <= m; i++)
        f >> b[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                c[i][j] = c[i-1][j-1]+1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    i = n, j = m, k = c[n][m];
    g << c[n][m] << "\n";
    while (i > 0 && j > 0)
    {
        while (c[i][j-1] == c[i][j]) j--;
        while (c[i-1][j] == c[i][j]) i--;
        rez[k--] = a[i];
        i--, j--;
    }
    for (i = 1; i <= c[n][m]; i++)
        g << rez[i] << " ";
    return 0;
}
