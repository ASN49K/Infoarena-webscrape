#include <stdio.h>

int GCD( int a, int b ) {
    if( !b )
        return a;
    return GCD(  b, a % b );
}
 
int main()
{
    int q;
 
    FILE *fin = fopen( "euclid2.in", "r" );
    FILE *fout = fopen( "euclid2.out", "w" );
    fscanf( fin, "%d", &q );

    while( q-- ) {
        int x, y;
        fscanf( fin, "%d %d", &x, &y );
        fprintf( fout, "%d\n", GCD( x, y ) );
    }
    fclose( fin );
    fclose( fout );
    return 0;
}