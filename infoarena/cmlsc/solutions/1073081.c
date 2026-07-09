#include <stdio.h>
#define NM_MAX 1024
#define INF 2000000000
FILE *out;
int v1[ NM_MAX ], v2[ NM_MAX ];
int d[ NM_MAX ] [ NM_MAX ];

void back ( int x, int y ){
    int scriu = 0;
    if ( ! ( x == 0 || y == 0 ) ){
        if ( d[ x - 1 ] [ y - 1 ] + 1 == d[ x ] [ y ] ){
            back ( x - 1, y - 1);
            scriu = 1;
        }
        else  if ( d[ x - 1] [ y ] == d[ x ] [ y ] ) back ( x - 1, y );
        else  back ( x, y - 1 );
    }
    else  if( v1[ x ] == v2 [ y ] ) scriu = 1;
    if(scriu)  fprintf ( out, "%d ", v1[ x ]);
    return ;
}

int maxim ( int a, int b ){
    if ( a > b ) return a;
    else  return b;
}

int main ()
{
    FILE *in = fopen ( "cmlsc.in", "r" );
    int n, m, i, j, max = -INF, l, c, x;
    fscanf ( in, "%d%d", &n, &m );

    for ( i = 0; i < n; i++ ){
        fscanf ( in, "%d", &v1[ i ] );
       // v1[ i ] = (char) x;
    }
    for ( i = 0; i < m; i++ ){
        fscanf ( in, "%d", &v2[ i ] );
        //v2[ i ] = (char) x;
    }

    for ( i = 0; i < n; i++ ){
        for ( j = 0; j < m; j++ ){
            if ( v1[ i ] == v2[ j ]){
                if ( i == 0 || j == 0)   d[ i ] [ j ] = 1;
                else  d[ i ] [ j ] = d[ i - 1 ] [ j - 1 ] + 1;
            }
            else{
                if ( i == 0 && j == 0 ) d[ i ] [ j ] = 0;
                else  if ( i == 0 )     d[ i ] [ j ] = d[ i ] [ j - 1 ];
                else  if ( j == 0 )     d[ i ] [ j ] = d[ i - 1 ] [ j ];
                else  d[ i ] [ j ] = maxim ( d[ i - 1 ] [ j ], d[ i ] [ j - 1 ] );
            }
            if ( max < d[ i ] [ j ] ){
                l = i;
                c = j;
                max = d[ i ] [ j ];
            }
        }
    }

    out = fopen ( "cmlsc.out", "w" );
    fprintf (out, "%d\n", max);
    back ( l, c );

    return 0;
}
