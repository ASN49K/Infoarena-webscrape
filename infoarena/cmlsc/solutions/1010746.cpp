#include <cstdio>

int m, n, a[1025], b[1025], c[1025][1025], d[1025], ind;

void Citire()
{
    FILE *F = fopen("cmlsc.in", "r");
    fscanf(F, "%d%d", &m, &n);
    for (int i = 1; i <= m; ++i)
        fscanf(F, "%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        fscanf(F, "%d", &b[i]);
    fclose(F);
}

void Matrice()
{
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else if (c[i][j - 1] >= c[i - 1][j])
                c[i][j] = c[i][j - 1];
            else
                c[i][j] = c[i - 1][j];
        }
    }
}

void Afisare()
{
    FILE *G = fopen("cmlsc.out", "w");
    fprintf(G, "%d\n", c[m][n]);
    for (int i = ind; i >= 1; --i)
        fprintf(G, "%d ", d[i]);
    fclose(G);
}

void Sir()
{
    int i, j;
    for (i = m, j = n; i >= 1 && j >= 1;)
    {
        if (a[i] == b[j])
        {
            d[++ind] = a[i];
            i--;
            j--;
        }
        else if (c[i - 1][j] > c[i][j - 1])
            i--;
        else if (c[i][j - 1] >= c[i - 1][j])
            j--;
    }
}

int main()
{
    Citire();
    Matrice();
    Sir();
    Afisare();
    return 0;
}
