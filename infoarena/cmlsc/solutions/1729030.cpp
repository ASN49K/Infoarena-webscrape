# include <bits/stdc++.h>

using namespace std;

const int Nmax = 1024 + 5;

int n, m, i, j;
int a[Nmax], b[Nmax], D[Nmax][Nmax], recons[Nmax];

int main ()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; ++i)
        scanf("%d ", &a[i]);

    for (i = 1; i <= m; ++i)
        scanf("%d ", &b[i]);

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            if (a[i] == b[j]) D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = max(D[i-1][j], D[i][j-1]);

    printf("%d\n", D[n][m]);

    i = n, j = m;

    int N = 0;

    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j]) recons[++N] = a[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1]) --j;
        else --i;

    }

    for (i = N; i >= 1; --i)
        printf("%d ", recons[i]);

    printf("\n");

    return 0;
}
