#include <stdio.h>

int cmmdc( int a, int b ){
    if( b==0 )
        return a;
    else
        return cmmdc( b, a%b );
}

int main()
{
    int n, a, b, i;
    FILE *fin, *fout;
    fin = fopen( "euclid2.in", "r" );
    fout = fopen( "euclid2.out", "w" );
    fscanf( fin, "%d", &n );
    for( i=0; i<n; i++ ){
        fscanf( fin, "%d%d", &a, &b );
        fprintf( fout, "%d\n", cmmdc( a, b) );
    }
    fclose( fin );
    fclose( fout );
    return 0;
}
