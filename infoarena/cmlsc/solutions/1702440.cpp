#include <cstdio>
#include <algorithm>
using namespace std;
const int NMAX = 1024;
int d[NMAX + 5][NMAX + 5];
int a[NMAX + 5], b[NMAX + 5], sol[NMAX + 5];
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m, nn, mm, maxim;
    scanf("%d %d", &n, &m);
    for (register int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (register int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);

    for (register int i = 1; i <= n; ++i)
        for (register int j = 1; j <= m; ++j)
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i][j - 1], d[i - 1][j]);
    printf("%d\n", d[n][m]);
    nn = n; mm = m;
    while (1)
    {
        if (a[n] == b[m])
        {
            sol[d[n][m]] = a[n];
            --n; --m;
            if (n == 0)
                break;
            if (m == 0)
                break;
        }
        else
        {
            maxim = max(d[n - 1][m], d[n][m - 1]);
            if (maxim == d[n - 1][m] && n != 1)
                --n;
            else if(m != 1)
                --m;
            else
                break;
        }
    }
    for (register int i = 1; i <= d[nn][mm]; ++i)
        printf("%d ", sol[i]);
    return 0;
}
