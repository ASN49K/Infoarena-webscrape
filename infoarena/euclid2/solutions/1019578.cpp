#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int gcd( int a , int b ){

    while ( b ){

       int aux = b ;
       b = a % b ;
       a = aux ;

    }

    return a ;

}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int a , b , n ;

    f >> n ;

    for( int i = 0 ; i < n ; i++ )
        f >> a >> b ,
        g << __gcd( a , b ) << '\n' ;

    return 0;
}
