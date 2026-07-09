#include <iostream>
#include <fstream>

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

    int a , b ;

    f >> a , b ;
    g << gcd( a , b ) ;

    return 0;
}
