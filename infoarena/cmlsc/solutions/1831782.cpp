#include <cstdio>
#include <iostream>
using namespace std;

#define NMAX 1025

int A[ NMAX ],
    B[ NMAX ],
    S[ NMAX ],
    D[ NMAX ][ NMAX ];


int main () {

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);


    int N, M, i, j, x, y, z, s, k;

    scanf( "%d%d",&N,&M );
    for ( i = 1; i <= N; ++i ) scanf( "%d",&A[ i ] );
    for ( i = 1; i <= M; ++i ) scanf( "%d",&B[ i ] );


    for ( i = 1; i <= N; ++i ) {
        for ( j = 1; j <= M; ++j )
            if ( A[ i ] == B[ j ] )
                D[ i ][ j ] = 1 + D[ i - 1 ][ j - 1 ];
            else
                D[ i ][ j ] = max( D[ i - 1 ][ j ], D[ i ][ j - 1 ] );
    }

    printf( "%d\n",D[ N ][ M ] );

    s = 0;
    i = N, j = M;
    k = D[ N ][ M ];
    while ( s != k ) {
        if ( A[ i ] == B[ j ] ) {
            S[ ++s ] = A[ i ];
            i--;
            j--;
        } else if ( D[ i - 1 ][ j ] > D[ i ][ j - 1 ] ) {
            i--;
        } else {
            j--;
        }
    }

    for ( i = s; i >= 1; --i )
        printf( "%d ",S[ i ] );

    return 0;

}
