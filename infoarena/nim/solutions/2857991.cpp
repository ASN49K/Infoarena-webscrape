#include <stdio.h>

int main()
{
    int q;
    FILE *fin = fopen( "nim.in", "r" );
    FILE *fout = fopen( "nim.out", "w" );

    fscanf( fin, "%d", &q );
    while( q-- ) {
        int n, s = 0, x;
        fscanf( fin, "%d", &n );
 
        for( int i = 1; i <= n; i++ ) {
            fscanf( fin , "%d", &x );
            s ^= x;
        }

        if( s != 0 )
            fprintf( fout, "DA\n" );
        else fprintf( fout, "NU\n" );
    }

    fclose( fin );
    fclose( fout );
    return 0;
}