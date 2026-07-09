/* 
 * File:   main.cpp
 * Author: bitone
 *
 * Created on October 12, 2010, 1:54 PM
 */
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#define MAX_N 1024

using namespace std;

/*
 * 
 */
vector< int > r;
int C[MAX_N][MAX_N], v[2][MAX_N];
int main(int argc, char** argv)
{
    int i, j;
    ifstream in( "cmlsc.in" );
    in>>v[0][0]>>v[1][0];
    for( i=1; i <= v[0][0]; ++i )
        in>>v[0][i];
    for( j=1; j <= v[1][0]; ++j )
        in>>v[1][j];
    for( i=1; i <= v[0][0]; ++i )
        for( j=1; j <= v[1][0]; ++j )
            if( v[0][i] == v[1][j] )
                C[i][j]=1+C[i-1][j-1];
            else C[i][j]=max( C[i-1][j], C[i][j-1] );
    for( i=v[0][0], j=v[1][0]; i && j; )
        if( v[0][i] == v[1][j] )
            r.push_back(v[0][i]), --i, --j;
        else if( C[i-1][j] >= C[i][j-1] )
                --i;
             else --j;
    ofstream out( "cmlsc.out" );
    out<<r.size()<<'\n';
    copy( r.rbegin(), r.rend(), ostream_iterator<int>( out, " " ) );
    out<<'\n';
    return EXIT_SUCCESS;
}

