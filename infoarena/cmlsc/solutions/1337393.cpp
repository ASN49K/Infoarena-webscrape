#include <fstream>
#include <algorithm>

#define IN "cmlsc.in"
#define OUT "cmlsc.out"

const int MAX = 1034 ;

using namespace std;

ifstream fin ( IN ) ;
ofstream fout ( OUT ) ;

int d [ MAX ] [ MAX ] ;

int a [ MAX ] , b [ MAX ] ;

int main()
{
    int n , m ;
    fin >> n >> m ;
    for ( register int i = 1 ; i <= n ; ++ i )
        fin >> a [ i ] ;
    for ( register int i = 1 ; i <= m ; ++ i )
        fin >> b [ i ] ;
    for ( register int i = 1 ; i <= n ; ++ i)
        for ( register int j = 1 ; j <= m ; ++ j)
            if ( a [ i ] == b [ j ] )
                d [ i ] [ j ] = 1 + d [ i - 1 ] [ j - 1 ] ;
            else
                d [ i ] [ j ] = max ( d [ i - 1 ] [ j ] , d [ i ] [ j - 1 ] ) ;
    fout << d [ n ] [ m ] << '\n' ;
    int i = n , j = m ;
    while ( i or j )
        if ( a [ i ] == b [ j ] ){
            fout << a [ i ] << " " ;
            i -- ;
            j -- ;
        }
        else
            if ( d [ i - 1 ] [ j ] < d [ i ] [ j - 1 ] )
                j -- ;
            else
                i -- ;
    return 0;
}
