
#include <cstdio>
#include <cstring>

using namespace std;

int maxthree(int a, int b, int c)
{
    if (a>b)
        if (a>c)
            return a;
    if (b>c)
        return b;
    return c;
}


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n, m , i, j, x, y;
    scanf("%d%d", &n, &m);

    int a[n+1], b[m+1];
    int din[n+1][m+1];
    din[0][0] = 0;

    for(i=1; i<=n; ++i)
    {
        scanf("%d", &a[i]);
        din[i][0] = 0;
    }
    for(j=1; j<=m; ++j)
    {
        scanf("%d", &b[j]);
        din[0][j] = 0;
    }

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if (a[i] == b[j])
                din[i][j] = maxthree(din[i-1][j-1] + 1, din[i-1][j], din[i][j-1]);
            else
                din[i][j] = maxthree(din[i-1][j-1], din[i-1][j], din[i][j-1]);
        }

    printf("%d\n", din[n][m]);
    int sol[din[n][m] + 1];
    x = n;
    y = m;
    i = din[n][m];

    while(i>0)
    {
        if(din[x][y] == din[x-1][y])
            x = x-1;
        else
            if(din[x][y] == din[x][y-1])
                y = y-1;
            else
                if(din[x][y] == din[x-1][y-1])
                {
                    x = x-1;
                    y = y-1;
                }
                else
                {
                    sol[i] = a[x];
                    --i;
                    x = x-1;
                    y = y-1;
                }
    }

    for(i=1; i<=din[n][m]; ++i)
        printf("%d ", sol[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
