/* 
 * File:   main.cpp
 * Author: salexandru
 *
 * Created on January 14, 2011, 1:15 PM
 */
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <algorithm>
#define N_MAX 1031
#define push push_back

using namespace std;

/*
 * 
 */
int C[N_MAX][N_MAX];
vector<int> v[2], r;
int main(int argc, char** argv)
{
    int i, j, k;
    ifstream in( "cmlsc.in" );
    in>>i>>j;
    v[0].push(i);
    v[1].push(j);
    for( i=0; i < v[0][0]; ++i )
    {
        in>>k;
        v[0].push(k);
    }
    for( j=0; j < v[1][0]; ++j )
    {
        in>>k;
        v[1].push(k);
    }
    for( i=1; i <= v[0][0]; ++i )
        for( j=1; j <= v[1][0]; ++j )
            if( v[0][i] == v[1][j] )
                C[i][j]=C[i-1][j-1]+1;
            else C[i][j]=max( C[i][j-1], C[i-1][j] );
    for( i=v[0][0], j=v[1][0]; i && j; )
        if( v[0][i] == v[1][j] )
        {
            r.push_back(v[0][i]);
            --i, --j;
        }
        else if( C[i-1][j] > C[i][j-1] )
                --i;
             else --j;
    ofstream out( "cmlsc.out" );
    out<<r.size()<<'\n';
    copy( r.rbegin(), r.rend(), ostream_iterator<int>( out, " " ) );
    out<<'\n';
    return EXIT_SUCCESS;
}

