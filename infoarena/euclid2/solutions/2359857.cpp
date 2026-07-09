#include <iostream>

using namespace std;

int v[ 1000005 ], b[ 1000005 ];

int bin ( int A )
{
    int NR = 0;
    while ( A > 0 )
    {
        if ( A % 2 == 1 )
            ++ NR;
        A /= 2;
    }
    return NR;
}

int main()
{
    int c, n, maxv = -1, maxx = -1;
    scanf( "%d%d", &c, &n );
    if ( c == 1 )
    {
        for ( int i = 1; i <= n; ++ i )
        {
            scanf( "%d", &v[i] );
            b[ i ] = bin (v[ i ]);
            if(b[ i ] > maxx )
            {
                maxx = b[ i ];
                maxv = v[ i ];
            }
            else
                if( b[ i ] == maxx )
                    if( maxv < v[ i ] )
                    maxv = v[ i ];
        }
        printf( "%d", maxv );
    }
    if( c == 2 )
    {

    }
    return 0;
}
