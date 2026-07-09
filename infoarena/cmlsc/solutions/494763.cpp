#include <vector>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#define MAX_N 1031

using namespace std;

/*
 *
 */
vector< int > start, r, _end;
int v[2][MAX_N], C[MAX_N][MAX_N];
inline int max( int x, int y )
{
	if( x >= y )
		return x;
	return y;
}
int main( void )
{
	int i, j, start1, start2, _count;
	ifstream in( "cmlsc.in" );
	in>>v[0][0]>>v[1][0];
	for( i=1; i <= v[0][0]; ++i )
		in>>v[0][i];
	for( i=1; i <= v[1][0]; ++i )
		in>>v[1][i];
	for( start1=start2=1; start1 <= v[0][0] && start2 <= v[1][0] && v[0][start1] == v[1][start2]; ++start1, ++start2 )
		start.push_back(v[0][start1]);
	for( _count=0; start1 <= v[0][0] && start2 <= v[1][0] && v[0][ v[0][0] ] == v[1][ v[1][0] ]; --v[0][0], --v[1][0], ++_count );
	for( i=start1; i <= v[0][0]; ++i )
		for( j=start2; j <= v[1][0]; ++j )
			if( v[0][i] == v[1][j] )
				C[i][j]=C[i-1][j-1]+1;
			else C[i][j]=max( C[i-1][j], C[i][j-1] );
	for( i=v[0][0], j=v[1][0]; i && j; )
		if( v[0][i] == v[1][j] )
			r.push_back(v[0][i]), --i, --j;
		else if( C[i-1][j] >= C[i][j-1] )
				--i;
			 else --j; 
	for( i=v[0][0]+1, v[0][0]+=_count; i <= v[0][0]; ++i )
		_end.push_back(v[0][i]);
	ofstream out( "cmlsc.out" );
	out<<( start.size()+_end.size()+r.size() )<<'\n';
	copy( start.begin(), start.end(), ostream_iterator<int>( out, " " ) );
	copy( r.rbegin(), r.rend(), ostream_iterator<int>( out, " " ) );
	copy( _end.begin(), _end.end(), ostream_iterator<int>( out, " " ) );
	out<<'\n';
	return EXIT_SUCCESS;
}
