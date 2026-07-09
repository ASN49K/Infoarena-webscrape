#include <cstdlib>
#include <fstream>
#include <iterator>
#include <algorithm>
#define MAX_N 1031

using namespace std;
/*
 *
 */
int C[MAX_N][MAX_N], v[2][MAX_N], r[MAX_N];
inline int max( int x, int y )
{
	return ( x >= y ? x : y );
}
int main( void )
{
	int i, j, k;
	ifstream in( "cmlsc.in" );
	in>>v[0][0]>>v[1][0];
	for( i=0; i < 2; ++i )
		for( j=1; j <= v[i][0]; ++j )
			in>>v[i][j];
	for( i=1; i <= v[0][0]; ++i )
		for( j=1; j <= v[1][0]; ++j )
			if( v[0][i] == v[1][j] )
				C[i][j]=1+C[i-1][j-1];
			else C[i][j]=max( C[i-1][j], C[i][j-1] );
	for( i=v[0][0], j=v[1][0], k=C[i][j]+1; i && j; )
		if( v[0][i] == v[1][j] )
			r[--k]=v[0][i], --i, --j;
		else if( C[i-1][j] >= C[i][j-1] )
				--i;
			 else --j;
	i=v[0][0]; j=v[1][0];
	ofstream out( "cmlsc.out" );
	out<<C[i][j]<<'\n';
	copy( r+1, r+C[i][j]+1, ostream_iterator<int>( out, " " ) );
	out<<'\n';
	return EXIT_SUCCESS;
}