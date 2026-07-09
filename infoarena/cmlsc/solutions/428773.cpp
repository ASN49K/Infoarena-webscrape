/* 
 * File:   main.cpp
 * Author: SpeeDemon
 *
 * Created on March 29, 2010, 3:34 PM
 */
#include <cstdlib>
#include <fstream>
#include <iterator>
#define Nmax 1025

/*
 *
 */
using namespace std;
int A[Nmax], B[Nmax], C[Nmax];
unsigned int  CMLSC[Nmax][Nmax];
inline  unsigned int& max( unsigned int& x, unsigned int& y )
{
    if( x > y )
        return x;
    return y;
}
int main( void )
{
    int N, M, i, j, k;
    ifstream in( "cmlsc.in" );
    in>>N>>M;
    for( i=1; i <= N; in>>A[i], ++i );
    for( j=1; j <= M; in>>B[j], ++j );
    for( i=1; i <= N; ++i )
        for( j=1; j <= M; ++j )
            if( A[i] == B[j] )
                CMLSC[i][j]=1+CMLSC[i-1][j-1];
            else CMLSC[i][j]=max( CMLSC[i-1][j], CMLSC[i][j-1] );
    for( i=N, j=M, k=CMLSC[N][M]; i && j; )
        if( A[i] == B[j] )
            C[k]=A[i], --i, --j, --k;
        else if( CMLSC[i-1][j] > CMLSC[i][j-1] )
                --i;
             else --j;
    ofstream out( "cmlsc.out" );
    out<<CMLSC[N][M]<<'\n';
    copy( C+1, C+CMLSC[N][M]+1, ostream_iterator<int>( out, " " ) );
    return EXIT_SUCCESS;
}
