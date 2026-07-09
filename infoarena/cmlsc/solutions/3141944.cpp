#include <fstream>
#include <vector>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
long long a [ 1050 ], b [ 1050 ] , dp [ 1050 ] [ 1050] ;
int main()
{

    int n , m ;
    cin >> n >> m ;

    for ( int i = 1; i <= n ; i ++ )
    {
        cin >> a[ i ];
    }

    for ( int i = 1; i <= m ; i ++ )
        cin >> b [ i ];

        for ( int i = 1; i <= n ; i ++ )
        {
            for ( int j = 1; j <= m ; j ++ )
            {
                if ( a [ i ] == b[ j ])
                {
                    dp [ i ] [ j ] = dp [i - 1] [ j - 1 ] + 1;
                }
                else
                    dp [ i ] [ j ] = max ( dp [ i -1 ] [ j ] , dp [ i ] [ j - 1 ]);
            }
        }

        cout << dp [ n ][ m] << '\n';

        vector<int> ans ;

        long long len = dp [n ] [ m ] ;
        long long i = n ;
        long long j = m ;
        while ( len != 0 )
        {

            if ( a [ i ] == b [ j ] )
            {
                ans.push_back( a[ i ]) ;
                i -- ;
                j --;
                len -- ;
            }
            else
                if ( dp [ i ] [ j ] == dp [ i - 1 ] [ j ] )
                    i -- ;
                else
                    j -- ;

        }

        for ( int i = ans.size() - 1; i >= 0 ; i -- )
            cout << ans[ i ] << " ";
    return 0;
}
