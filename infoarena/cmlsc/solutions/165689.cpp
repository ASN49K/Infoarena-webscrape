#include <stdio.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int n, m;
int i, j, k;
int a[1030], b[1030];
int d[1030][1030];

void Solve();
void Drum(int i, int j);

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for ( i = 1; i <= n; i++ )     
        scanf("%d", &a[i]);
    for ( i = 1; i <= m; i++ )
        scanf("%d", &b[i]);
        
    Solve();
    printf("%d\n", d[n][m]);
    Drum(n, m);
    
    return 0;
}

void Solve()
{
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            if ( a[i] == b[j] )
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = Max(d[i-1][j], d[i][j-1]);
}

void Drum(int i, int j)
{
    if ( d[i][j] == 1 && a[i] == b[j] )
    {
        printf("%d", a[i]);
        return;
    }
    if ( a[i] == b[j] )
        Drum(i-1, j-1), printf(" %d", a[i]);
    else
        if ( d[i-1][j] > d[i][j-1] ) Drum(i-1, j);
        else                         Drum(i, j-1);
}

        
                 
