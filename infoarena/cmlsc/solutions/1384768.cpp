#include <fstream>
#define lmax 1024+1
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int lg[lmax][lmax], a[lmax], b[lmax];
int fin[lmax];
int m, n, i, j, p;

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
                lg[i][j] = lg[i-1][j-1] + 1;
            else
                lg[i][j] = max(lg[i-1][j], lg[i][j-1]);

    i = n, j = m;
    while (lg[i][j])
    {
        while (lg[i][j] == lg[i-1][j])  i--;
        while (lg[i][j] == lg[i][j-1])  j--;
        p++, fin[p] = a[i];
        i--, j--;
    }

    g << p << "\n";
    for (i = p; i >= 1; i--)
        g << fin[i] << " ";
    return 0;
}
