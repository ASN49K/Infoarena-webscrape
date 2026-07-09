#include<cstdio>

using namespace std;

const int NMAX = 1024;

int m, n;
int mat[NMAX + 1][NMAX + 1];
int a[NMAX + 1], b[NMAX + 1];

int ma(int a, int b)
{
    if(a > b == true)
    {
        return a;
    }
    return b;
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            mat[i][j] = ma(ma(mat[i - 1][j], mat[i][j - 1]), mat[i - 1][j - 1] + (a[i] == b[j]));
        }
    }

    int r[NMAX + 1], pos = 0;
    while(m > 0 && n > 0)
    {
        if(mat[m][n] > ma(mat[m - 1][n], mat[m][n - 1]))
        {
            pos++;
            r[pos] = a[m];
            m--;
            n--;
        }
        else if(mat[m - 1][n] > mat[m][n - 1])
        {
            m--;
        }
        else
        {
            n--;
        }
    }

    printf("%d\n", pos);
    while(pos > 0)
    {
        printf("%d ", r[pos]);
        pos--;
    }
}
