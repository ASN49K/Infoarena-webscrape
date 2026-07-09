#include <vector>
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
	{
		for( j=1; j <= v[1][0]; ++j )
			if( v[0][i] == v[1][j] )
				Cmlsc[i][j]=1+Cmlsc[i-1][j-1];
			else Cmlsc[i][j]=_max( Cmlsc[i][j-1], Cmlsc[i-1][j] );
	}
	for( i=v[0][0], j=v[1][0], k=Cmlsc[i][j]; i && j; )
		if( v[0][i] == v[1][j] )
			v[2][k]=v[0][i], --k, --i, --j;
		else if( Cmlsc[i-1][j] <= Cmlsc[i][j-1] )
		        --j;
		     else --i;
	ofstream out( "cmlsc.out" );
	out<<Cmlsc[v[0][0]][v[1][0]]<<'\n';
	copy( v[2]+1, v[2]+1+Cmlsc[v[0][0]][v[1][0]], ostream_iterator<int>( out, " " ) );
	out<<'\n';
	return EXIT_SUCCESS;
}
