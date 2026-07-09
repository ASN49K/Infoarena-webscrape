# include <stdio.h>
# include <stdlib.h>

int cmmdc( int a, int b ) {
    int r;

    while ( b > 0 ) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    FILE *fin = fopen( "euclid2.in", "r" ), *fout = fopen( "euclid2.out", "w" );

    int n, i, a, b;

    fscanf( fin, "%d", &n );

    for ( i = 0; i < n; i ++ ) {
        fscanf( fin, "%d%d", &a, &b );
        fprintf( fout, "%d\n", cmmdc( a, b ) );
    }

    fclose( fin );
    fclose( fout );

    return 0;
}
