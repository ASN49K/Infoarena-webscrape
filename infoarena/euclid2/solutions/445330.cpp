/* 
 * File:   main.cpp
 * Author: virtualdemon
 *
 * Created on April 23, 2010, 3:21 PM
 */
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
int main(int argc, char** argv)
{
    int N, a, b;
    ifstream in( "euclid2.in" );
    ofstream out( "euclid2.out" );
    for( in>>N; N; --N )
    {
        in>>a>>b;
        out<<gcd( a, b )<<'\n';
    }
    return (EXIT_SUCCESS);
}

