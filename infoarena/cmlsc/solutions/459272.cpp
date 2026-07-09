#include <vector>
#include <cstdlib>
#include <fstream>
#include <iterator>
#define Nmax 1031

/*
 *
 */
using namespace std;
int CMLSC[Nmax][Nmax];
int main()
{
    int N, M, i, j;
    int v[Nmax], w[Nmax];
    vector< int > r;
    ifstream in( "cmlsc.in" );
    in>>N>>M;
    for( i=1; i <= N; in>>v[i], ++i );
    for( j=1; j <= M; in>>w[j], ++j );
    for( i=1; i <= N; ++i )
        for( j=1; j <= M; ++j )
            if( v[i] == w[j] )
                CMLSC[i][j]=CMLSC[i-1][j-1]+1;
            else CMLSC[i][j]=max( CMLSC[i-1][j], CMLSC[i][j-1] );
    for( i=N, j=M; i && j; )
        if( v[i] == w[j] )
            r.push_back(v[i]), --i, --j;
        else if( CMLSC[i-1][j] >= CMLSC[i][j-1] )
                --i;
            else --j;
    ofstream out( "cmlsc.out" );
    out<<CMLSC[N][M]<<"\n";
    copy( r.rbegin(), r.rend(), ostream_iterator< int >( out, " " ) );
    return EXIT_SUCCESS;
}
