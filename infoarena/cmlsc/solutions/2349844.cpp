#include <cstdio>

using namespace std;

int n, m, mat[1025][1025], x[1025], y[1025];

void bac (int i, int j)
{
    if (i < 1 || j < 1 || !mat[i][j]) {return;}
    if (x[i] == y[j])
    {
        mat[i][j] = 0;
        bac (i-1, j-1);
        printf ("%d ", x[i]);
    }
    if (mat[i-1][j] > mat[i][j-1])
    {
        bac (i-1, j);
    }
    else
    {
        bac (i, j -1);
    }
}

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    int i, j;
    scanf ("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
    {
        scanf ("%d", &x[i]);
    }
    for (i = 1; i <= m; ++i)
    {
        scanf ("%d", &y[i]);
    }

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            if (x[i] == y[j])
            {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else
            {
                mat[i][j] = (mat[i-1][j] > mat[i][j-1]) ? mat[i-1][j] : mat[i][j-1];
            }
        }
    }
    printf ("%d\n", mat[n][m]);
    bac (n, m);
    return 0;
}
