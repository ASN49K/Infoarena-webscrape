/* 
 * File:   main.cpp
 * Author: VirtualDemon
 *
 * Created on April 3, 2010, 10:04 AM
 */
#include <cstdlib>
#include <fstream>
#include <iterator>
#define Nmax 1025

/*
 *
 */
using namespace std;
int C[Nmax][Nmax];
int A[Nmax], B[Nmax], R[Nmax];
inline const int& max( const int& x, const int& y )
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
    for( i=1; i <= N; in>>B[i], ++i );
    for( i=1; i <= N; ++i )
        for( j=1; j <= M; ++j )
            if( A[i] == B[j] )
                C[i][j]=1+C[i-1][j-1];
            else C[i][j]=max( C[i-1][j], C[i][j-1] );
    for( i=N, j=M, k=C[i][j]; k; )
        if( A[i] == B[j] )
            R[k]=A[i], --i, --j, --k;
        else if( C[i-1][j] > C[i][j-1] )
                --i;
             else --j;
    ofstream out( "cmlsc.out" );
    out<<C[N][M]<<'\n';
    copy( R+1, R+C[N][M]+1, ostream_iterator<int>( out, " " ) );
    out<<'\n';
    return EXIT_SUCCESS;
}



