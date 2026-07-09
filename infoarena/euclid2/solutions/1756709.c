#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin, *fout;
    int a, b, r, t, i;
    fin = fopen( "euclid2.in", "r" );
    fout = fopen( "euclid2.out", "w" );
    fscanf( fin, "%d", &t );
    for ( i = 0; i < t; i++ ) {
        fscanf( fin, "%d%d", &a, &b );
        r = 0;
        while ( b > 0 ) {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf( fout, "%d\n", a );
    }
    fclose( fin );
    fclose( fout );
    return 0;
}
