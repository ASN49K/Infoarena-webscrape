#include <fstream>
#include <cstdlib>

/*
 *
 */
using namespace std;
inline int gcd( int x, int y )
{
	int r=y;
	while( r )
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main( void )
{
	int N, x, y;
	ifstream in( "euclid2.in" );
	ofstream out( "euclid2.out" );
	for( in>>N; N; --N )
	{
		in>>x>>y;
		out<<gcd( x, y )<<'\n';
	}
	return EXIT_SUCCESS;
}