#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j;
short a[1025], b[1025];
short sol[1025];
int din[1025][1025];

int main()
{
    f >> n >> m;
    for (i = 1; i <= n; i++)
        f >> a[i];
    for (i = 1; i <= m; i++)
        f >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                din[i][j] = din[i-1][j-1] + 1;
            else
                din[i][j] = max(din[i-1][j], din[i][j-1]);
    g << din[n][m] << '\n';
    i = n, j = m;
    while (i > 0 && j > 0)
    {
        while (din[i-1][j] == din[i][j]) i--;
        while (din[i][j-1] == din[i][j]) j--;
        sol[din[i][j]] = a[i];
        i--, j--;
    }
    for (i = 1; i <= din[n][m]; i++)
        g << sol[i] << ' ';
    return 0;
}
