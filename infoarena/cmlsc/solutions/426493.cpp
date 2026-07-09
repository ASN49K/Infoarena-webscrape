/* 
 * File:   main.cpp
 * Author: virtualdemon
 *
 * Created on March 27, 2010, 8:40 AM
 */
#include <fstream>
#include <cstdlib>
#include <iterator>

/*
 *
 */
using namespace std;
int C[ 1025 ][ 1025 ], v[ 1025 ], v2[ 1025 ], r[ 1025 ];
inline const int& max( const int& x, const int& y )
{
    if( x < y )
        return y;
    return x;
}
int main( void )
{
    int N, M, i, j, k=0;
    ifstream in( "cmlsc.in" );
    in>>N>>M;
    for( i=1; i <= N; ++i )
        in>>v[i];
    for( j=1; j <= M; ++j )
        in>>v2[j];
    for( i=1; i <= N; ++i )
        for( j=1; j <= M; ++j )
            if( v[i] == v2[j] )
                C[i][j]=1+C[i-1][j-1];
            else C[i][j]=max( C[i-1][j], C[i][j-1] );
    for( i=N, j=M, k=C[N][M]-1; i && j; )
        if( v[i] == v2[j] )
            r[k]=v[i], --i, --j, --k;
        else if( C[i-1][j] > C[i][j-1] )
                --i;
            else --j;
    ofstream out( "cmlsc.out" );
    out<<C[N][M]<<'\n';
    copy( r, r+C[N][M], ostream_iterator<int>( out, " " ) );
    return EXIT_SUCCESS;
}