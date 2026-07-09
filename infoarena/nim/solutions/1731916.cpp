#include <fstream>

using namespace std ;

ifstream f ("nim.in") ;
ofstream g ("nim.out") ;

int t , n , x , xorsum ;

int main ()
{
 for ( f >> t ; t ; --t )
     for ( f >> n , xorsum = 0 ; n ; --n )
        {
         f >> x ;
         xorsum ^= x ;
         if ( n == 1 )
            if ( xorsum == 0 )
                g << "NU\n" ;
            else
                g << "DA\n" ;
        }
}
