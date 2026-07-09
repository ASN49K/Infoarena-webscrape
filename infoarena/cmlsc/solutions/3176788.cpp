#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
long long n , m ;

long long a[ 1025  ] , b [ 1025 ] , dp [ 1025 ] [ 1025 ];
int main()
{
    cin >> n >> m ;

    for(int i = 1; i <= n ; i ++ )
        cin >> a[ i ];

    for (int i = 1; i <= m ; i ++ )
        cin >> b[ i ];
    for ( int i = 1; i <= n ; i ++ )
    {
        for ( int j = 1; j <= m ; j ++ )
        {
            if ( a[ i ] == b[ j ] )
            {
                dp[ i ][ j ] = dp[ i - 1] [ j - 1 ] + 1;

            }
            else
            {
                dp [ i ][ j ] = max ( dp [ i ] [ j - 1  ] , dp [ i - 1 ] [ j ] ) ;
            }
        }
    }

    cout << dp[ n ][ m ] << '\n';

    vector<int>sol ;

    while (n >= 1 && m >= 1 )
    {
        if ( a[ n ] == b[ m ] )
        {
            sol.push_back( a[ n ] ) ;
            n -- ;
            m -- ;
        }
        else
            if ( dp [ n ] [ m ] == dp [ n - 1 ] [ m  ] )
            n -- ;
        else
            m -- ;
    }

   for (int i = sol.size() - 1 ; i >= 0 ; i -- )
    cout << sol [ i ] << " ";



    return 0;
}
