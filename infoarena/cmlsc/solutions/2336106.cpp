#include <bits/stdc++.h>
#define pb push_back
using namespace std ;
const int NR = 1025 ;
ifstream in ("cmlsc.in") ;
ofstream out ("cmlsc.out") ;
int16_t a [ NR ] , b [ NR ] , cmlsc [ NR ][ NR ] ;
int n , m ;
void recursion ( int i , int j )
{
    if ( !cmlsc [ i ][ j ] )    return ;

    if ( a [ i ] == b [ j ] )
    {
        recursion( i - 1 , j ) ;
         out << a [ i ] << " " ;
        return ;
    }
    if ( cmlsc [ i - 1 ][ j ] > cmlsc [ i ][ j - 1 ] )
    {
        recursion( i - 1 , j ) ;
        return ;
    }
    else
    {
        recursion( i , j - 1 ) ;
        return ;
    }
}
int main ()
{
      in >> n >> m ;

    for ( int i = 1 ; i <= n ; ++ i )   in >> a [ i ] , cmlsc [ i ][ 0 ] = 0 ;
    for ( int i = 1 ; i <= m ; ++ i )   in >> b [ i ] , cmlsc [ 0 ][ i ] = 0 ;

    for ( int i = 1 ; i <= n ; ++ i )
    for ( int j = 1 ; j <= m ; ++ j )
    {
        if ( a [ i ] == b [ j ] )
            cmlsc [ i ][ j ] = 1 + cmlsc [ i - 1 ][ j - 1 ] ;
        else
            cmlsc [ i ][ j ] = max ( cmlsc [ i - 1 ][ j ] , cmlsc [ i ][ j - 1 ] ) ;
    }
    out << cmlsc [ n ][ m ] << "\n" ;
    recursion( n , m ) ;
    return 0 ;
}
