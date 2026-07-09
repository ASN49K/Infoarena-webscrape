#include <stdio.h>

int A[ 1025 ], B[ 1025 ];
short Din[ 1025 ][ 1025 ];

int Ans[ 1025 ], LenAns;
short Mat[ 1025 ][ 1025 ]; // tinem drumul pe care am mers ( 1 - sus; 2 - stanga; 3 - sus-stanga )

inline int Max( int x, int y ) {
    return x > y ? x : y;
}

short Best( int x, int y ) {
    if( Din[ x ][ y ] != -1 ) {
        return Din[ x ][ y ];
    } else {
        if( A[ x ] == B[ y ] ) {
            Mat[ x ][ y ] = 3;
            return ( Din[ x ][ y ] = Best( x - 1, y - 1 ) + 1 );
        } else {
            short st = Best( x, y - 1 ), sus = Best( x - 1, y );
            if( st < sus ) {
                Mat[ x ][ y ] = 1;
                return ( Din[ x ][ y ] = sus );
            } else {
                Mat[ x ][ y ] = 2;
                return ( Din[ x ][ y ] = st );
            }
        }
    }
}

int main( ) {
    FILE * fin, * fout;
    fin = fopen( "cmlsc.in", "r" );
    fout = fopen( "cmlsc.out", "w" );

    // Citire
    int M, N;
    fscanf( fin, "%d%d", &M, &N );


    int i, j;
    for( i = 1; i <= M; i ++ ) {
        fscanf( fin, "%d", A + i );
    }
    for( i = 1; i <= N; i ++ ) {
        fscanf( fin, "%d", B + i );
    }

    // Initializare Din cu -1 in [1..M][1..N]
    for( i = 1; i <= M; i ++ ) {
        for( j = 1; j <= N; j ++ ) {
            Din[ i ][ j ] = -1;
        }
    }

    // Afisare maxim
    fprintf( fout, "%hd\n", Best( M,  N ) );

    // Afisare subsir
    short x = M, y = N;
    while( x != 0 && y != 0 ) {
        if( Mat[ x ][ y ] == 3 ) {
            Ans[ ++ LenAns ] = A[ x ];
            x --;
            y --;
        } else if( Mat[ x ][ y ] == 2 ) {
            y --;
        } else {
            x --;
        }
    }

    for( i = LenAns; i >= 1; i -- ) {
        fprintf( fout, "%d ", Ans[ i ] );
    }

    fclose( fin );
    fclose( fout );
    return 0;
}
