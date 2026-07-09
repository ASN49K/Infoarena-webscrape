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
    FILE *f=fopen( "euclid2.out", "wt" );
    FILE *g=fopen( "euclid2.in", "rt" );
    fscanf( g, "%d", &T );
    for( ; T; --T )
    {
        fscanf( g, "%d%d", &a, &b );
        fprintf( f, "%d\n", gcd( a, b ) );
    }
    return EXIT_SUCCESS;
}
