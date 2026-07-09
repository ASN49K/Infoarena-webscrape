/* 
 * File:   main.cpp
 * Author: bitone
 *
 * Created on August 18, 2010, 10:44 AM
 */
#include <fstream>
#include <cstdlib>
#include <iterator>
#define MAX_N 1027

using namespace std;

/*
 * 
 */
signed short int v[3][MAX_N];
signed short int C[MAX_N][MAX_N];
inline signed short int max( signed short int x, signed short int y )
{
    if( x >= y )
        return x;
    return y;
}
int main( void )
{
    unsigned short int i, j;
    ifstream in( "cmlsc.in" );
    in>>v[0][0]>>v[1][0];
    for( i=0; i < 2; ++i )
        for( j=1; j <= v[i][0]; ++j )
            in>>v[i][j];
    for( i=1; i <= v[0][0]; ++i )
        for( j=1; j <= v[1][0]; ++j )
            if( v[0][i] == v[1][j] )
                C[i][j]=1+C[i-1][j-1];
            else C[i][j]=max( C[i][j-1], C[i-1][j] );
    v[2][0]=C[i-1][j-1];
    for( i=v[0][0], j=v[1][0]; i && j; )
        if( v[0][i] == v[1][j] )
            v[2][ --v[2][0] ]=v[0][i], --i, --j;
        else if( C[i-1][j] >= C[i][j-1] )
                --i;
             else --j;
   ofstream out( "cmlsc.out" );
   out<<C[ v[0][0] ][ v[1][0] ]<<'\n';
   copy( v[2], v[2]+C[ v[0][0] ][ v[1][0] ], ostream_iterator<signed short int>(out," ") );
   out<<'\n';
   return EXIT_SUCCESS;
}

