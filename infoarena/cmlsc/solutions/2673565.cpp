#include <stdio.h>
#include <stdlib.h>
#define N 1 << 10

int dp[N + 1][N + 1], a[N + 1], b[N + 1];

FILE *in, *out;

int max(int x, int y)
{
    return (x > y ? x : y);
}

void subsir(int l, int c)
{
    if (dp[l][c] == 0)
    {
        return;
    }
    if (a[l] == b[c])
    {
        subsir(l - 1, c - 1);
        fprintf(out, "%d ", a[l]);
    }
    else
    {
        if (dp[l - 1][c] > dp[l][c - 1])
        {
            subsir(l - 1, c);
        }
        else
        {
            subsir(l, c - 1);
        }
    }
}

int main()
{
    int na, nb, lmax = 0;
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
    fscanf(in, "%d%d", &na, &nb);
    int i, j;
    for (i = 1; i <= na; i++)
    {
        fscanf(in, "%d", &a[i]);
    }
    for (i = 1; i <= nb; i++)
    {
        fscanf(in, "%d", &b[i]);
    }
    fclose(in);
    ///constructia matricei dp
    for (i = 1; i <= na; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            lmax = max(lmax, dp[i][j]);
        }
    }
    fprintf(out, "%d\n", lmax);
    subsir(na, nb);
    fclose(out);
    return 0;
}
