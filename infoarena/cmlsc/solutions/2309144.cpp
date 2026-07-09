#include <fstream>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std ;

ifstream f ("cmlsc.in") ;
ofstream g ("cmlsc.out") ;

 int main ()
 {
    int n , m , i , j ; f >> n >> m ;
    int a [ n + 1 ][ m + 1 ] = {0} ;
    int x [ n + 1 ] ;
    int y [ n + 1 ] ;
    int ans [ max ( n , m ) + 1 ] = {0} ;
    for ( i = 1 ; i <= n ; ++ i )   f >> x [ i ] ;
    for ( i = 1 ; i <= m ; ++ i )   f >> y [ i ] ;

    for ( i = 1 ; i <= n ; ++ i )
    for ( j = 1 ; j <= m ; ++ j )

    if ( x [ i ] == y [ j ] )  {a [ i ][ j ] = a [ i - 1 ][ j - 1 ] + 1 ; if ( !ans [ a [ i ][ j ] ] ) ans [ a [ i ][ j ] ] = x [ i ] ; }
    else                        a [ i ][ j ] = max ( a [ i ][ j - 1 ] , a [ i - 1 ][ j ] ) ;

    g << a [ n ][ m ] << "\n" ;
    for ( i = 1 ; ans [ i ] ; ++ i )    g << ans [ i ] << " " ;
    g << "\n" ;

 f.close() ;
 g.close() ;
 return 0 ;
 }
