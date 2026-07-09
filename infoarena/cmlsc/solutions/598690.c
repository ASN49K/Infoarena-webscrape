#include <stdio.h>
#define N 500
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

    int m, n, vm[N], vn[N], mat[N][N], subsir[N];
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

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(vn[i] == vm[j])
                mat[i][j] = 1 + max(mat[i-1][j], mat[i][j-1]);
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
    i = n;
    j = m;
    int l = mat[n][m];
    while(mat[i][j] != 0)
    {
        if(mat[i][j] > mat[i-1][j])
        {
            subsir[l--] = vn[i];
            i--;
            j--;
        }
        else
            i--;
    }

    printf("%d\n", mat[n][m]);
    for(i = 1; i <= mat[n][m]; i++)
        printf("%d ", subsir[i]);

    return 0;
}
