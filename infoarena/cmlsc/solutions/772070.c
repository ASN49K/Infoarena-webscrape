#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 1025

int LCS_length(
        int C[MAX_DIM][MAX_DIM],
        unsigned char X[MAX_DIM], unsigned char Y[MAX_DIM],
        int m, int n )
{
    int i, j;

    for ( i = 0; i <= m; ++i ) {
        C[i][0] = 0;
    }
    for ( j = 1; j <= n; ++j ) {
        C[0][j] = 0;
    }

    for ( i = 1; i <= m; ++i ) {
        for ( j = 1; j <= n; ++j ) {
            if ( X[i] == Y[j] ) {
                C[i][j] = C[i-1][j-1] + 1;
            } else {
                C[i][j] = C[i][j-1] > C[i-1][j] ? C[i][j-1] : C[i-1][j] ;
            }
        }
    }

    return C[m][n];
}

void LCS_backtrack(
        int C[MAX_DIM][MAX_DIM],
        unsigned char X[MAX_DIM], unsigned char Y[MAX_DIM],
        int i, int j )
{
    if ( i != 0 && j != 0 ) {
        if ( X[i] == Y[j] ) {
            LCS_backtrack( C, X, Y, i-1, j-1 );

            printf( "%d ", X[i] );
        } else {
            if ( C[i][j-1] > C[i-1][j] ) {
                LCS_backtrack( C, X, Y, i, j-1 );
            } else {
                LCS_backtrack( C, X, Y, i-1, j );
            }
        }
    }
}

int main( void )
{
    int i, j;
    int m, n;
    unsigned char X[MAX_DIM], Y[MAX_DIM];
    int C[MAX_DIM][MAX_DIM];

    freopen( "cmlsc.in", "r", stdin );
    freopen( "cmlsc.out", "w", stdout );

    scanf( "%d %d", &m, &n );

    for ( i = 1; i <= m; ++i ) {
        scanf( "%c", &X[i] );
    }
    for ( j = 1; j <= n; ++j ) {
        scanf( "%c", &Y[j] );
    }

    printf( "%d\n", LCS_length( C, X, Y, m, n ) );
    LCS_backtrack( C, X, Y, m, n );

    return EXIT_SUCCESS;
}
