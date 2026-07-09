#include <stdio.h>
#include <stdlib.h>

short aparitii[1073741825];

int main() {
    FILE *fin = fopen( "nim.in", "r" ), *fout = fopen( "nim.out", "w" );
    int t, n, i, j, xor, p2, a;
    fscanf( fin, "%d", &t );
    for ( i = 0; i < t; i ++ ) {
        for ( j = 1; j < 1073741824; j *= 2 )
            aparitii[j] = 0;
        fscanf( fin, "%d", &n );
        for ( j = 0; j < n; j ++ ) {
            fscanf( fin, "%d", &a );
            while ( a > 0 ) {
                p2 = 1;
                while ( p2 * 2 <= a )
                    p2 *= 2;
                aparitii[p2] ++;
                a -= p2;
            }
        }
        for ( j = 1; j < 32; j *= 2 )
            printf( "%d ", aparitii[j] );
        printf( "\n" );
        xor = 0;
        for ( j = 1; j < 1073741824; j *= 2 )
            if ( aparitii[j] % 2 == 1 )
                xor += j;
        if ( xor > 0 )
            fprintf( fout, "DA\n" );
        else
            fprintf( fout, "NU\n" );
    }
    return 0;
}
