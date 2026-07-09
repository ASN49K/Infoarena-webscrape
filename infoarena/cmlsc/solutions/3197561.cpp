#include <stdio.h>

#define MAXN 1024

short ans[ MAXN + 1 ][ MAXN + 1 ];
short first[ MAXN + 1 ], second[ MAXN + 1 ];
short solution[ MAXN + 1 ];

FILE *fin, *fout;

int main()
{
    int n, m, i, j, maxsecv;
    fin = fopen( "cmlsc.in", "r" );

    fscanf( fin, "%d%d", &n, &m );

    for( i = 1; i <= n; i++ )
    {
        fscanf( fin, "%hd", &first[ i ] );
    }

    for( j = 1; j <= m; j++ )
    {
        fscanf( fin, "%hd", &second[ j ] );
    }

    fclose( fin );

    for( i = 1; i <= n; i++ )
    {
        for( j = 1; j <= m; j++ )
        {
            if( first[ i ] == second[ j ] )
            {
                ans[ i ][ j ] = 1 + ans[ i - 1 ][ j - 1 ];
            }
            else
            {
                if( ans[ i ][ j - 1 ] > ans[ i - 1 ][ j ] )
                {
                    ans[ i ][ j ] = ans[ i ][ j - 1 ];
                }
                else
                {
                    ans[ i ][ j ] = ans[ i - 1 ][ j ];
                }
            }
        }
    }


    fout = fopen( "cmlsc.out", "w" );
    fprintf( fout, "%hd\n", ans[ n ][ m ] );

    maxsecv = i = ans[ n ][ m ];
    while( i > 0 )
    {
        if( ans[ n - 1 ][ m ] == i )
        {
            n--;
        }
        else if( ans[ n ][ m - 1 ] == i )
        {
            m--;
        }
        else
        {
            i--;
            solution[ i ] = first[ n ];
            n--;
            m--;
        }
    }

    for( i = 0; i < maxsecv; i++ )
    {
        fprintf( fout, "%hd ", solution[ i ] );
    }
    fclose( fout );
    return 0;
}
