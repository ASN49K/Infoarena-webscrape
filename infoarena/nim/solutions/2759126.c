#include <stdio.h>

int main() {
    FILE *fin, *fout;
    int t, n, a, xor, i, j;

    fin = fopen( "nim.in", "r" );
    fout = fopen( "nim.out", "w" );

    fscanf( fin, "%d", &t );
    for ( i = 0; i < t; i++ ) {
        fscanf( fin, "%d", &n );
        xor = 0;
        for ( j = 0; j < n; j++ ) {
            fscanf( fin, "%d", &a );
            xor ^= a;
        }
        if ( xor == 0 )
            fprintf( fout, "NU\n" );
        else
            fprintf( fout, "DA\n" );
    }

    fclose( fin );
    fclose( fout );

    return 0;
}
