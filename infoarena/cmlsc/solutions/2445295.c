#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b?a : b);
}
int main()
{
    int n, m, i, j;
    FILE* f = fopen("cmlsc.in", "r");
    FILE* g = fopen("cmlsc.out", "w");
    fscanf(f, "%d %d", &n, &m);
    int v1[n];
    int v2[m];
    for (i = 0; i < n; i++)
    {
        fscanf(f, "%d", &v1[i]);
    }
    for (j = 0; j < m; j++)
    {
        fscanf(f, "%d", &v2[j]);
    }
    int mat[n][m];
    memset(mat, 0, n * m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (v1[i] == v2[j] && ((i == 0) || (j == 0)))
            {
                mat[i][j] = 1;
            }
            if (v1[i] == v2[j] && (i > 0) && (j > 0))
            {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            if (v1[i] != v2[j])
            {
                if (i > 0 && j > 0)
                {
                    mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
                }
                else if (i > 0)
                {
                    mat[i][j] = mat[i-1][j];
                }
                else if (j > 0)
                {
                    mat[i][j] = mat[i][j-1];
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", mat[n-1][m-1]);
    int findPath = 0;
    int last1 = n - 1;
    int last2 = m - 1;
    int dim = 0;
    int v[100];
    while (findPath != 1 && last1 > 0 && last2 > 0)
    {
        if (mat[last1][last2] == 1)
        {
            v[dim++] = v1[last1];
            findPath = 1;
            break;
        }
        if (mat[last1-1][last2] > mat[last1][last2-1])
        {
            last1 = last1 - 1;
        }
        else
        {
            if (mat[last1][last2] > mat[last1][last2-1])
            {
                v[dim++] = v1[last1];
            }
            last2 = last2 - 1;
        }
    }
    for (i = dim - 1; i >= 0; i--)
    {
        fprintf(g, "%d ", v[i]);
    }
    return 0;
}
