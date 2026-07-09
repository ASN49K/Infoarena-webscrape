#include <stdio.h>

int gcd( int a, int b ) {
    if( b ) {
        return gcd( b, a % b );
    } else {
        return a;
    }
}

int main( ) {
    FILE * fin, * fout;
    fin =  fopen( "euclid2.in", "r" );
    fout = fopen( "euclid2.out", "w" );

    int T;
    fscanf( fin, "%d", &T );

    int i;
    for( i = 1; i <= T; i ++ ) {
        int a, b;
        fscanf( fin, "%d%d", &a, &b );
        fprintf( fout, "%d\n", gcd( a, b ) );
    }

    fclose( fin );
    fclose( fout );
}
