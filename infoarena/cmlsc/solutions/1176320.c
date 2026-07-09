#include <stdio.h>
#define NM_MAX 1024
FILE *out;
int v1[ NM_MAX ], v2[ NM_MAX ];
int din[ NM_MAX ][ NM_MAX ];

void back ( int x, int y ){
    if ( din[ x ][ y ] == 0 )   return ;
    while ( din[ x ][ y ] == din[ x ][ y - 1 ] )    y--;
    while ( din[ x ][ y ] == din[ x - 1 ][ y ] )    x--;
    if ( x > 0 && y > 0 )   back ( x - 1, y - 1 );
    fprintf ( out, "%d ", v1[ x ] );
    return ;
}

int max ( int a, int b ){
    if ( a < b )    return b;
    return a;
}

int main ()
{
    FILE *in = fopen ( "cmlsc.in", "r" );
    int n, m;
    fscanf ( in, "%d%d", &n, &m );
    int i, j;
    for ( i = 0; i < n; i++ )   fscanf ( in, "%d", &v1[ i ] );
    for ( i = 0; i < m; i++ )   fscanf ( in, "%d", &v2[ i ] );
    fclose ( in );
    for ( i = 0; i < n; i++ ){
        for ( j = 0; j < m; j++ ){
            if ( v1[ i ] == v2[ j ] ){
                if ( i == 0 || j == 0 ) din[ i ][ j ] = 1;
                else  din[ i ][ j ] = 1 + din[ i - 1 ][ j - 1 ];
            }
            else{
                if ( i == 0 && j == 0 ) din[ i ][ j ] = 0;
                else  if ( i == 0 )  din[ i ][ j ] = din[ i ][ j - 1 ];
                else  if ( j == 0 )  din[ i ][ j ] = din[ i - 1 ][ j ];
                else    din[ i ][ j ] = max ( din[ i - 1 ][ j ], din[ i ][ j - 1 ] );
            }
        }
    }
    out = fopen ( "cmlsc.out", "w" );
    fprintf ( out, "%d\n", din[ n - 1 ][ m - 1 ] );
    back ( n - 1, m - 1 );
    fclose ( out );
    return 0;
}
