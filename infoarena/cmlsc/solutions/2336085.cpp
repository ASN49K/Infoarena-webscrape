#include <bits/stdc++.h>
#define pb push_back
using namespace std;
ifstream in ("cmlsc.in") ;
ofstream out ("cmlsc.out") ;
deque < int > st ;
int main ()
{
    int n , m ; in >> n >> m ;
    int a [ n + 1 ] , b [ m + 1 ] ;
    int cmlsc [ n + 1 ][ m + 1 ] ;
    for ( int i = 1 ; i <= n ; ++ i )   in >> a [ i ] , cmlsc [ i ][ 0 ] = 0 ;
    for ( int i = 1 ; i <= m ; ++ i )   in >> b [ i ] , cmlsc [ 0 ][ i ] = 0 ;

    for ( int i = 1 ; i <= n ; ++ i )
    for ( int j = 1 ; j <= m ; ++ j )
    {
        if ( a [ i ] == b [ j ] )
            cmlsc [ i ][ j ] = 1 + cmlsc [ i - 1 ][ j - 1 ] , st.pb( i ) ;
        else
            cmlsc [ i ][ j ] = max ( cmlsc [ i - 1 ][ j ] , cmlsc [ i ][ j - 1 ] ) ;
    }

    out << cmlsc [ n ][ m ] << "\n" ;
    while ( st.size() ) out << a [st.front() ] << " " , st.pop_front() ;
    return 0 ;
}
