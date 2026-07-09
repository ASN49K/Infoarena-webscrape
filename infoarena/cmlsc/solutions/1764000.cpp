#include <cstdio>
#include <algorithm>>
#define NMAX 1024
using namespace std;
int a[NMAX+5], b[NMAX+5], d[NMAX+5][NMAX+5], s[NMAX+5];
int main () {
    freopen ( "cmlsc.in", "r", stdin );
    freopen ( "cmlsc.out", "w", stdout );
    int m, n, i, j, l;
    scanf ( "%d %d", &m, &n );
    for ( i = 1 ; i <= m ; ++ i )
        scanf ( "%d", &a[i] );
    for ( i = 1 ; i <= n ; ++ i )
        scanf ( "%d", &b[i] );
    for ( i = 1 ; i <= m ; ++ i )
        for ( j = 1 ; j <= n ; ++ j ) {
            if ( a[i] == b[j] )
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max ( d[i-1][j], d[i][j-1] );
        }
    i = m;
    j = n;
    l = 0;
    while ( i ) {
        if ( a[i] == b[j] ) {
            s[++l] = a[i];
            i--;
            j--;
        }
        else if ( d[i-1][j] < d[i][j-1] )
            j--;
        else
            i--;
    }
    printf ( "%d\n", l );
    for ( i = l ; i >= 1 ; --i )
        printf ( "%d ", s[i] );
    return 0;
}
