#include <fstream>
#include <iterator>
#define Nmax 1024
#define foreach( i, from, till ) for( i=from; i <= till; ++i )

/*
 *
 */
using namespace std;
int CMLSC[Nmax][Nmax];
int v[Nmax], s[Nmax], r[Nmax];
inline const int& max( const int& x, const int& y )
{
	if( x > y )
		return x;
	return y;
}
int main( void )
{
	int N, M, i, j, l=-1, max=0;
	ifstream in( "cmlsc.in" );
	in>>N>>M;
	foreach( i, 1, N )
		in>>v[i];
	foreach( j, 1, M )
		in>>s[j];
	foreach( i, 1, N )
	{
		foreach( j, 1, M )
			if( v[i] == s[j] )
			{
				CMLSC[i][j]=CMLSC[i-1][j-1]+1;
				if( CMLSC[i][j] > max )
					max=CMLSC[i][j];
			}
			else CMLSC[i][j]=::max( CMLSC[i-1][j], CMLSC[i][j-1] );
	}
	l=max;
	for( i=N, j=M; i && j; )
		if( v[i] == s[j] )
			r[--l]=v[i], --i, --j;
		else if( CMLSC[i-1][j] > CMLSC[i][j-1] )
				 --i;
			 else --j;
	ofstream out( "cmlsc.out" );
	out<<(max)<<'\n';
	copy( r, r+max, ostream_iterator<int>( out, " " ) );
	return 0;
}
