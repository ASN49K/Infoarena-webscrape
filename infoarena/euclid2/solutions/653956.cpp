#include <fstream>
#include <cstdlib>

using namespace std;

int gcd( int x, int y )
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
	int T, x, y;

	ifstream in( "euclid2.in" );
	ofstream out( "euclid2.out" );

	for( in>>T; T; --T )
	{
		in>>x>>y;
		out<<gcd( x, y )<<'\n';
	}

	return EXIT_SUCCESS;
}