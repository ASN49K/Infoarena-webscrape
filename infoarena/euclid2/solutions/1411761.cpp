#include <iostream>
#include <fstream>

using namespace std ;

ifstream f ("euclid2.in") ;
ofstream g ("euclid2.out") ;

int main ()
{
 int n , a , b ;
 f >> n ;
 for  ( int i = 1 ; i <= n ; ++i )
    {
     f >> a >> b ;
     int r ;
     while( b )
        {
         r = a % b ;
         a = b ;
         b = r ;
        }
     g << a << "\n" ;
    }
 f.close() ;
 g.close() ;
 return 0 ;
}
