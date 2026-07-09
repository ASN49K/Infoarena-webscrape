#include <cstdio>

int m, n, a[1025], b[1025], c[1025][1025];

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
    int i = 1, j = 1;
    fprintf(G, "%d\n", c[m][n]);
    while (i <= m && j <= n)
    {
        if (c[i + 1][j + 1] > c[i][j] && a[i + 1] == b[j + 1])
        {
            i++;
            j++;
            fprintf(G, "%d ", a[i]);
        }
        else if (c[i + 1][j] > c[i][j] && a[i + 1] == b[j])
        {
            i++;
            fprintf(G, "%d ", a[i]);
        }
        else if (c[i][j + 1] > c[i][j] && a[i] == b[j + 1])
        {
            j++;
            fprintf(G, "%d ", b[j]);
        }
        else if (i < m)
            i++;
        else if (j < n)
            j++;
        else if (i == m && j == n)
            break;
    }
}

int main()
{
    Citire();
    Matrice();
    Afisare();
    return 0;
}
