#include <stdio.h>
#include <algorithm>

using namespace std;

const int N_MAX = 1026;
int a[N_MAX], b[N_MAX], n, m, d[N_MAX][N_MAX], sol[N_MAX];

void read ()
{
    freopen ("cmlsc.in", "r", stdin);
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i ++ )
        scanf("%d", &a[i]);
    for (int j = 1; j <= n; j ++ )
        scanf("%d", &b[j]);
    fclose(stdin);
}

void solve ()
{
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            if ( a[i] == b[j] )
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max (d[i-1][j], d[i][j-1]);
        }

    int i = m, j = n;
    while ( i && j )
    {
        if ( a[i] == b[j] )
            sol[++sol[0]] = a[i], i --, j --;
        else if ( d[i-1][j] < d[i][j-1] )
            j --;
        else
            i --;
    }
}

void write ()
{
    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", d[m][n]);
    for (int i = sol[0]; i >= 1; i -- )
        printf("%d ", sol[i]);
    fclose(stdout);
}

int main()
{
    read();
    solve();
    write();
    return 0;
}
