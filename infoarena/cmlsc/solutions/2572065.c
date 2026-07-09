#include <stdio.h>
#include <stdlib.h>
#define N 1024

int m, n, a[N], b[N], dp[1+N][1+N];
FILE *in, *out;//fisierele de intrare/iesire

int max(int x, int y)
{
    //max a 2 numere
    return (x > y ? x : y);
}

void subsir(int l, int c)
{
    //refac recursiv subsirul
    if (l == 0 || c == 0)
    {
        return;
    }
    if (a[l] == b[c])
    {
        subsir(l - 1, c - 1);//inversez ordinea facand apel inainte de afisare
        fprintf(out, "%d ", a[l]);
    }
    else
    {
        if (dp[l-1][c] > dp[l][c-1])
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
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
    int i, j;
    //citirea numerelor din siruri
    fscanf(in, "%d%d", &m, &n);
    for (i = 1; i <= m; i++)
    {
        fscanf(in, "%d", &a[i]);
    }
    for (j = 1; j <= n; j++)
    {
        fscanf(in, "%d", &b[j]);
    }
    //construiesc matricea
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                //extind cmlsc pentru prefixele de lungime i-1, respectiv j-1
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                //subsirul creste odata cu prefixele
            }
        }
    }
    fprintf(out, "%d\n", dp[m][n]);//cel mai lung subsir comun al sirurilor intregi
    subsir(m, n);
    return 0;
}
