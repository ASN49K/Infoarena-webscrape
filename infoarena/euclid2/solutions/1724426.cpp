
#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in") ;
ofstream out("euclid2.out") ;

int t , a , b ;

int euclid( int x , int y )
{
    if( !y )
        return x ;
    return euclid( y , x % y ) ;
}

int main() {

    in >> t ;
    
    for( int  i = 1 ; i <= t ; i ++)
    {
        in >> a >> b ;
        
        out << euclid( a , b ) << '\n' ;
    }
    return 0;
}

