#include <stdio.h>
#include <stdlib.h>
#define N 1024
int n, m, dp[1+N][1+N], a[N], b[N];
FILE *in, *out;
int max(int x, int y)
{
    return (x > y ? x : y);
}
void subsir(int l, int c)
{
    if(l==0||c==0)
    {
        return;
    }
    if(a[l]==b[c])
    {
        subsir(l-1, c-1);
        fprintf(out, "%d ", a[l]);
    }
    else
        {
            if(dp[l-1][c]>dp[l][c-1])
            {
                subsir(l-1, c);
            }
            else
                {
                    subsir(l, c-1);
                }
        }
}
int main()
{
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
    int i, j;
    fscanf(in, "%d%d", &m, &n);
    for (i = 1; i <= m; i++)
    {
        fscanf(in, "%d", &a[i]);
    }
    for (j = 1; j <= n; j++)
    {
        fscanf(in, "%d", &b[j]);
    }
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
    subsir(m, n);
    return 0;
}
