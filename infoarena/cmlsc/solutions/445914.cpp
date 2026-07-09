/* 
 * File:   main.cpp
 * Author: virtualdemon
 *
 * Created on April 24, 2010, 11:31 AM
 */
#include <cstdlib>
#include <fstream>
#include <iterator>
#define Nmax 1030

/*
 * 
 */
using namespace std;
int C[Nmax][Nmax];
int v[Nmax], w[Nmax], r[Nmax];
int main(int argc, char** argv)
{
    int N, M, i, j, k;
    ifstream in( "cmlsc.in" );
    in>>N>>M;
    for( i=1; i <= N; in>>v[i], ++i );
    for( j=1; j <= M; in>>w[j], ++j );
    for( i=1; i <= N; ++i )
        for( j=1; j <= M; ++j )
            if( v[i] == w[j] )
                C[i][j]=1+C[i-1][j-1];
            else C[i][j]=max( C[i][j-1], C[i-1][j] );
    for( i=N, j=M, k=C[i][j]; i && j; )
        if( v[i] == w[j] )
            r[k]=v[i], --k, --i, --j;
        else if( C[i-1][j] > C[i][j-1] )
                --i;
            else --j;
    ofstream out( "cmlsc.out" );
    out<<C[N][M]<<'\n';
    copy( r+1, r+1+C[N][M], ostream_iterator<int>( out, " " ) );
    return (EXIT_SUCCESS);
}

