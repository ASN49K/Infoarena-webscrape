
#include <stdio.h>
#include <stdlib.h>

 int main ( void )

  {

    int m, n, total = 0, i = 0,j = 0;
    int a [ 1024 ], b [ 1024 ], x;

    freopen ( "cmlsc.in", "r", stdin );
    freopen ( "cmlsc.out", "w", stdout );

    fscanf ( stdin, "%d", &m );
    fscanf ( stdin, "%d", &n );

    while ( j < m )
     {
       fscanf ( stdin, "%d", &a[j]);
       j++;
     }

    while ( i < n )
     {
       fscanf ( stdin, "%d", &x );
       for ( j = 0; j < m; j++ )
        if ( a [ j ] == x )
         {
           b [ total ] = x; total++;
           a [ j ] = a [ --m ]; break;
         }
       i++;
     }

    fprintf( stdout, "%d\n", total );

    for ( i = 0; i < total; i++ )
     fprintf( stdout, "%d ", b [ i ] );

    fclose ( stdout ); fclose ( stdin );

    return 0;

  }

