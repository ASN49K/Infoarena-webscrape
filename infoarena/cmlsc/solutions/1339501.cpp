#include <cstdio>
#include <algorithm>
#define nmax 1024+5
using namespace std;

int a[nmax], b[nmax];
int c[nmax][nmax];
int n, m;

void afisare_recursiva(int lin, int col)
{
    if (lin >= 1 && col >= 1)
    {
        if (a[lin] == b[col])
        {
            afisare_recursiva(lin-1, col-1);
            printf("%d ", a[lin]);
        }
        else if (c[lin-1][col] > c[lin][col-1])
            afisare_recursiva(lin-1, col);
        else
            afisare_recursiva(lin, col-1);
    }
}
int main()
{
    int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (j = 1; j <= m; j++)
        scanf("%d", &b[j]);

    for (i =1 ; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                c[i][j] = c[i-1][j-1]+1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);

    printf("%d\n", c[n][m]);
    afisare_recursiva(n, m);
    return 0;
}
