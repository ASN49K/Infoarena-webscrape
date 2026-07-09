#include <cstdio>
#include <algorithm>

using namespace std;

int a[1100], b[1100], v[1024][1024], c[1024];

int main ()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    int n, m;
    scanf ("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf ("%d", &a[i]);

    for (int j = 1; j <= m; ++j)
        scanf ("%d", &b[j]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i] == b[j]) v[i][j] = v[i - 1][j - 1] + 1;
            else v[i][j] = max (v[i - 1][j], v[i][j - 1]);

    int k = 0;
    for (int i = n, j = m; i && j;)
    {
        if (a[i] == b[j]) c[++k] = a[i], --i, --j;
        else if (i == 1 && j > 1) --j;
        else if (i > 1 && j == 1) --i;
        else if (v[i][j - 1] > v[i - 1][j]) --j;
        else --i;
    }

    printf ("%d\n", k);

    for (int i = k; i; --i)
        printf ("%d ", c[i]);

    printf ("\n");

    return 0;
}
