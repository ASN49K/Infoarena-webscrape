/* 
 * File:   main.cpp
 * Author: bitone
 *
 * Created on August 18, 2010, 10:39 AM
 */
#include <fstream>
#include <cstdlib>

using namespace std;

/*
 * 
 */
inline int gcd( int x, int y )
{
    int z=1;
    while( z )
    {
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}
int main(int argc, char** argv)
{
    int T, x, y;
    ifstream in( "euclid2.in" );
    ofstream out( "euclid2.out" );
    for( in>>T; T; --T )
    {
        in>>x>>y;
        out<<gcd( x, y )<<'\n';
    }    
    return EXIT_SUCCESS;
}

