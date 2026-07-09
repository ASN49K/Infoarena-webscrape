#include <stdio.h>
#include <stdlib.h>
#define N 1024

int a[1+N], b[1+N], dp[1+N][1+N];

FILE *in, *out;

int max(int x, int y)
{
    return (x > y ? x : y);
}

void refac_subsir(int l, int c)
{
    if (l == 0 || c == 0)
    {
        return;
    }
    if (a[l] == b[c])
    {
        refac_subsir(l-1, c-1);
        fprintf(out, "%d ", a[l]);
    }
    else if (dp[l-1][c] > dp[l][c-1])
    {
        refac_subsir(l-1, c);
    }
    else
    {
        refac_subsir(l, c-1);
    }
}

int main()
{
    int m, n, i, j;
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
    fscanf(in, "%d%d", &m, &n);
    for (i = 1; i <= m; i++)
    {
        fscanf(in, "%d", &a[i]);
    }
    for (j = 1; j <= n; j++)
    {
        fscanf(in, "%d", &b[j]);
    }
    fclose(in);
    //construiesc matricea dp,
    //cu dp[i][j] = lung max a unui subsir comun prefixelor de lungime i din a
    //si respectiv j din b
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    fprintf(out, "%d\n", dp[m][n]);
    refac_subsir(m, n);
    return 0;
}
