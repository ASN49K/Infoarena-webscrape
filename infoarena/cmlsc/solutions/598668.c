#include <stdio.h>

// cel mai lung subsir comun;

int max(int a, int b)
{
    if(a >= b)
        return a;
    return b;
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int m, n, vm[256], vn[256], mat[256][256], subsir[256];
    int i, j;

    scanf("%d", &m);
    scanf("%d", &n);

    for(i = 1; i <= m; i++)
    {
        mat[0][i] = 0;
        scanf("%d", &vm[i]);
    }
    for(i = 1; i <= n; i++)
    {
        mat[i][0] = 0;
        scanf("%d", &vn[i]);
    }

    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            if(vn[i] == vm[j])
                mat[i][j] = 1 + max(mat[i-1][j], mat[i][j-1]);
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
    i = m;
    j = n;
    int l = mat[m][n];
    while(mat[i][j] != 0)
    {
        if(mat[i][j] > mat[i-1][j])
        {
            subsir[l--] = vm[i+1];
            i--;
            j--;
        }
        else
            i--;
    }

    printf("%d\n", mat[m][n]);
    for(i = 1; i <= mat[m][n]; i++)
        printf("%d ", subsir[i]);

    /*printf("\n\n");
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    scanf("%&c");*/
    return 0;
}
