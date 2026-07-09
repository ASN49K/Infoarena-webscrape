#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

short int a[1030], b[1030], mat[1030][1030], n, m;

void citire()
{
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(i = 1; i <= m; i++)
        scanf("%d", &b[i]);
}

void solve()
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
    {
        if(a[i] == b[j])
            mat[i][j] = mat[i-1][j-1] + 1;
        else
            mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
    }
    printf("%d\n", mat[n][m]);
}

void debug()
{
    int i, j;
    for(i = 0; i<= n; i++)
    {
        for(j = 0; j <= m; j++)
            printf("%d ", mat[i][j]);
            printf("\n");
    }
}

void afisare(int x = n, int y = m)
{
    if(x == 0 || y == 0)
        return;
    if(a[x] == b[y])
    {
        afisare(x-1, y-1);
        printf("%d ", a[x]);
        return;
    }
    if(mat[x][y-1] > mat[x-1][y])
    {
        afisare(x, y-1);
        return;
    }
    afisare(x-1, y);
    return;
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    citire();
    solve();
    afisare();
    return 0;
}
