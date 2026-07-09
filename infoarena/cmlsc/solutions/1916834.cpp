#include <fstream>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int m, n, a[ 1025], b[ 1025 ], d[ 1025 ][ 1025 ], sir[ 1025 ], i ,j, q;
int main(){
    f >> n >> m;
    for ( i = 1; i <= n; ++i ) f >> a[ i ];
    for ( i = 1; i <= m; ++i ) f >> b[ i ];
    for ( i = 1; i <= n; ++i ){
        for ( i = 1; i <= n; ++i  )
            for ( j = 1; j <= m; ++j ){
                if ( a[ i ] ==  b[ j ] )
                    d[ i ][ j ] = 1 + d[ i - 1 ][ j -1  ];
                else d[ i ][ j ] = max ( d[ i - 1 ][ j ], d[ i ][ j - 1 ] );
            }
    }
    for( i = n, j = m; i; ){
        if ( a[ i ] == b[ j ] )
            sir[ ++q ] = a[ i ], --i, --j;
        else if ( d[ i - 1 ][ j ] <d[ i ][ j - 1 ] ) --j;
                else --i;
    }
    g << q << "\n";
    for( i = q; i >= 1; --i )g << sir[ i ] << " ";
}
