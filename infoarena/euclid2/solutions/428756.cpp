/* 
 * File:   main.cpp
 * Author: SpeeDemon
 *
 * Created on March 29, 2010, 3:26 PM
 */
#include <fstream>
#include <cstdlib>

/*
 *
 */
using namespace std;
inline unsigned int gcd( unsigned int a, unsigned int b )
{
    unsigned r;
    while( b )
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main( void )
{
    unsigned int T, a, b;
    ifstream in( "euclid2.in" );
    ofstream out( "euclid2.out" );
    in>>T;
    for( ; T; --T )
    {
        in>>a>>b;
        out<<gcd( a, b )<<'\n';
    }
    return EXIT_SUCCESS;
}
