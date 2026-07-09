/* 
 * File:   main.cpp
 * Author: virtualdemon
 *
 * Created on March 18, 2010, 3:11 PM
 */
#include <fstream>

/*
 *
 */
using namespace std;
inline int cmmdc( int a, int b )
{
    int r=b%a;
    while( r )
    {
        r=b%a;
        a=b;
        b=r;
    }
    return a;
}
int main( void )
{
    int n, a, b;
    ifstream in( "euclid2.in");
    ofstream out( "euclid2.out" );
    in>>n;
    for( ; n; --n )
    {
        in>>a>>b;
        out<<cmmdc( a, b )<<'\n';
    }
    return 0;
}