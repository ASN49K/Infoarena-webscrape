#include <cstdlib>
#include <fstream>

using namespace std;
/*
 *
 */
inline int gcd( int x, int y )
{
	int r=y;
	while( y )
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main( void )
{
	int T, a, b;
	ifstream in( "euclid2.in" );
	ofstream out( "euclid2.out" );
	for( in>>T; T; --T )
	{
		in>>a>>b;
		out<<gcd( a, b )<<'\n';
	}
	return EXIT_SUCCESS;
}