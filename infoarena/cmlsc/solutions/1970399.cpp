#include<cstdio>

using namespace std;

const int NMAX = 1024;

int n,m;
int mat[1 + NMAX][1 + NMAX];
int v1[1 + NMAX], v2[1 + NMAX];
int res[1 + NMAX];

int ma(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &v1[i]);
    }

    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &v2[i]);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(v1[i] == v2[j])
            {
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else
            {
                mat[i][j] = ma(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    int y = n;
    int x = m;
    int sz = mat[n][m];

    while(sz > 0)
    {
        if(v1[y] == v2[x])
        {
            res[sz] = v1[y];
            sz--;
            y--;
            x--;
        }
        else if(mat[y - 1][x] > mat[y][x - 1])
        {
            y--;
        }
        else
        {
            x--;
        }
    }

    printf("%d\n", mat[n][m]);
    for(int i = 1; i <= mat[n][m]; i++)
    {
        printf("%d ", res[i]);
    }
}
