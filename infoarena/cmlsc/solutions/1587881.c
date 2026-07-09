#include <stdio.h>
#include <stdlib.h>

#define INPUT "cmlsc.in"
#define OUTPUT "cmlsc.out"

FILE    *in;
FILE    *out;

int     mx(int a, int b)
{
    if(a > b)
        return (a);
    else
        return (b);
}

void    trace(int **tab, int *a, int n, int m)
{
    while (n > 0 && tab[n][m] == tab[n - 1][m])
        n--;
    if (n != 0)
    {
        n--;
        m--;
        trace(tab, a, n, m);
        if (n > 0)
            fprintf(out, "%d ", a[n + 1]);
    }
}

int     cmlsc(int *a, int n, int *b, int m)
{
    int     **tab;
    int     i;
    int     j;

    tab = (int**)malloc(sizeof(int*) * (n + 1));
    for (i = 0; i <= n; i++)
        tab[i] = (int*)malloc(sizeof(int) * (m+1));

    for (i = 0; i <= n; i++)
        tab[i][0] = 0;
    for (i = 0; i <= m; i++)
        tab[0][i] = 0;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                tab[i][j] = tab[i - 1][j - 1] + 1;
            else
                tab[i][j] = mx(tab[i][j - 1], tab[i - 1][j]);
    fprintf(out, "%d\n", tab[n][m]);
    trace(tab, a, n, m);
}

void    read(int *a, int n)
{
    int     i;

    for (i = 1; i <= n; i++)
        fscanf(in, "%d", a + i);
}

int     main()
{
    int     a[1025];
    int     b[1025];
    int     len_a;
    int     len_b;

    in = fopen(INPUT, "r");
    out = fopen(OUTPUT, "w");
    fscanf(in, "%d", &len_a);
    fscanf(in, "%d", &len_b);
    read(a, len_a);
    read(b, len_b);
    cmlsc(a, len_a, b, len_b);
}
