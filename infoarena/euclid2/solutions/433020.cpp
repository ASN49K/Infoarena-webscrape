/* 
 * File:   main.cpp
 * Author: VirtualDemon
 *
 * Created on April 3, 2010, 9:49 AM
 */
#include <cstdio>
#include <cstdlib>
#include <fstream>

/*
 *
 */
using namespace std;
inline int gcd( int a, int b )
{
    int r;
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
    int T, a, b;
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
