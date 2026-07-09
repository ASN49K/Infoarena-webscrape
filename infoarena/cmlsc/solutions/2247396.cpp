#include <cstdio>
#include <iostream>
using namespace std;

int V[ 1024 ][ 1024 ];
int A[ 1024 ], B[ 1024 ], S[ 1024 ];

int main () {

    freopen( "cmlsc.in", "r", stdin );
    freopen( "cmlsc.out", "w", stdout );

    int n, m, i, j, ma, mi, p;

    scanf( "%d%d", &n, &m );
    for ( i = 1; i <= n; ++i ) scanf( "%d", &A[ i ] );
    for ( i = 1; i <= m; ++i ) scanf( "%d", &B[ i ] );

    for ( i = 1; i <= n; ++i ) {
        for ( j = 1; j <= m; ++j )
            if ( A[ i ] == B[ j ] ) V[ i ][ j ] = 1 + V[ i  - 1 ][ j - 1 ];
            else V[ i ][ j ] = max( V[ i ][ j - 1 ], V[ i - 1 ][ j ] );

    }

    printf( "%d\n", V[ n ][ m ] );

    int s = 0, k = V[ n ][ m ];
    i = n; j = m;

    while ( s != k ) {
        if ( A [ i ] == B[ j ] ) {
            S[ ++s ] = A[ i ];
            i--; j--;
        } else if ( V[ i - 1 ][ j ] > V[ i ][ j - 1 ] ) {
            i--;
        } else {
            j--;
        }
    }

    for ( i = s; i >= 1; --i ) printf( "%d ", S[ i ] );

    return 0;

}
