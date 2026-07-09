#include <stdio.h>

int euclid(int a, int b)
{
    int r;

    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    FILE *fin, *fout;

    fin = fopen( "euclid2.in", "r" );
    fout = fopen( "euclid2.out", "w" );

    long a,b,n,i;

    fscanf( "%d", &n );

    for( i = 0 ; i < n ; i++ )
    {
        fscanf( fin, "%d %d", &a, &b );
        fprintf( fout, "%d\n", euclid( a, b ) );
    }
    return 0;
}
