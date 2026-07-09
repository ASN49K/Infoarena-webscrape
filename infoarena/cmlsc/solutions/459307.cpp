#include <vector>
#include <cstdlib>
#include <fstream>
#include <iterator>
#define Nmax 1031

/*
 *
 */
using namespace std;
bool was[600];
vector< int > r;
int main( void )
{
    int N, M, i, j;
    ifstream in( "cmlsc.in" );
    in>>N>>M;
    for( i=1; i <= N; ++i )
    {
        in>>j;
        if( j < 0 )
          j=256-j;
        was[j]=true;
    }
    for( j=1; j <= M; ++j )
    {
        in>>i;
        if( i < 0 )
            i=256-i;
        if( was[i] )
            r.push_back(i);
    }
    ofstream out( "cmlsc.out" );
    out<<r.size()<<'\n';
    copy( r.begin(), r.end(), ostream_iterator< int >( out, " " ) );
    out<<'\n';
    return EXIT_SUCCESS;
}
