#include <cstdio>

const int NMAX = 100;

int v[NMAX + 1][NMAX + 1];

int main ()
{
    freopen ("joc5.in", "r", stdin);
    freopen ("joc5.out", "w", stdout);

    while (true)
    {
        int n, s = 0;

        scanf ("%d", &n);
        if (n == 0) break;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf ("%d", &v[i][j]);
        for (int i = 1; i <= n; ++i)
            s ^= v[i][i];
        if (s == 0)
            printf ("2\n");
        else
            printf ("1\n");
    }

    return 0;
}
