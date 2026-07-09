#include <stdio.h>
#include <stdlib.h>
#define N 1024

int l_max[N+1][N+1], a[N+1], b[N+1], m, n;
FILE *in, *out;

int max(int x, int y)
{
    return (x > y ? x : y);
}

void refac_subsirul(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    if (a[i] == b[j])
    {
        refac_subsirul(i - 1, j - 1);
        fprintf(out, "%d ", a[i]);
    }
    else
    {
        if (l_max[i-1][j] > l_max[i][j-1])
        {
            refac_subsirul(i - 1, j);
        }
        else
        {
            refac_subsirul(i, j - 1);
        }
    }
}

int main()
{
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
    fscanf(in, "%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        fscanf(in, "%d", &a[i]);
    }
    for (int j = 1; j <= n; j++)
    {
        fscanf(in, "%d", &b[j]);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                l_max[i][j] = 1 + l_max[i-1][j-1];
            }
            else
            {
                l_max[i][j] = max(l_max[i-1][j], l_max[i][j-1]);
            }
        }
    }
    fprintf(out, "%d\n", l_max[m][n]);
    refac_subsirul(m, n);
    fclose(in);
    fclose(out);
    return 0;
}
