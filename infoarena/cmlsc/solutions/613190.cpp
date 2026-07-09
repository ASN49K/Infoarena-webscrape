#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#define N_MAX 1031

using namespace std;
int v[3][N_MAX];
int Cmlsc[N_MAX][N_MAX];
inline int _max( int x, int y ) { return x >= y ? x : y; }
int main( void )
{
    int i, j, k;
    ifstream in( "cmlsc.in" );
    in>>v[0][0]>>v[1][0];
    for( i=1; i <= v[0][0]; ++i )
        in>>v[0][i];
    for( i=1; i <= v[1][0]; ++i )
        in>>v[1][i];
    for( i=1; i <= v[0][0]; ++i )
        for( j=1; j <= v[1][0]; ++j )
            if( v[0][i] == v[1][j] )
                Cmlsc[i][j]=Cmlsc[i-1][j-1]+1;
            else Cmlsc[i][j]=_max( Cmlsc[i-1][j], Cmlsc[i][j-1] );
    k=v[2][0]=Cmlsc[v[0][0]][v[1][0]];
    for( i=v[0][0], j=v[1][0]; i && j; )
        if( v[0][i] == v[1][j] )
            v[2][k]=v[1][j], --k, --i, --j;
        else if( Cmlsc[i-1][j] >= Cmlsc[i][j-1] )
                 --i;
             else --j;
    ofstream out( "cmlsc.out" );
    out<<v[2][0]<<'\n';
    copy( v[2]+1, v[2]+v[2][0]+1, ostream_iterator<int>( out, " " ) );
    out<<'\n';
    return EXIT_SUCCESS;
}
