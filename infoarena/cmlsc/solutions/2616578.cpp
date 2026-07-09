#include <fstream>
#define MAX 1024
using namespace std;
int a[ MAX ][ MAX ];
int x[ MAX + 1 ], y[ MAX + 1 ];
int v[ MAX * MAX + 1 ];

ifstream cin( "cmlsc.in" );
ofstream cout( "cmlsc.out" );

int main()
{
    int n, m, i, l, c, unde;
    cin >> n >> m;
    for( i = 1; i <= n; i++ )
        cin >> x[ i ];
    for( i = 1; i <= m; i++ )
        cin >> y[ i ];

    for( l = 1; l <= m; l++ )
        for( c = 1; c <= n; c++ ){
            if( x[ c ] == y[ l ] )
                a[ l ][ c ] = a[ l - 1 ][ c - 1 ] + 1;
            else
                a[ l ][ c ] = max( a[ l - 1 ][ c ], a[ l ][ c - 1 ] );
        }

    cout << a[ m ][ n ] << '\n';

    l = m;
    c = n;
    unde = a[ m ][ n ];
    while( l != 0 && c != 0 ){
        ///cout << l << ' ' << c << '\n';
        if( y[ l ] == x[ c ] )
            --l, --c, v[ --unde ] = y[ l + 1 ];
        else if( a[ l ][ c - 1 ] >= a[ l - 1 ][ c ] )
            --c;
        else
            --l;
    }

    for( i = 0; i < a[ m ][ n ]; i++ )
        cout << v[ i ] << ' ';

    return 0;
}