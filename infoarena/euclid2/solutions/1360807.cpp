#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, x, y, t;
    FILE *f = fopen( "euclid2.in", "r" );
    FILE *g = fopen( "euclid2.out", "w" );

    fscanf( f, "%d", &n );
    for( int i = 0; i < n; i++ )
    {
        fscanf( f, "%d%d", &x, &y );
        while( y != 0 )
        {
            t = y;
            y = x % y;
            x = t;
        }
        fprintf( g, "%d\n", t );
    }

    fclose( f );
    fclose( g );
    return 0;
}
