#include <fstream>
#include <cstdlib>

using namespace std;
typedef unsigned int uint;

inline uint gcd( uint x, uint y )
{
	uint r=y;

	while( r )
	{
		r=x%y;
		x=y;
		y=r;
	}

	return x;
}
int main()
{
	uint T, a, b;
	ifstream in( "euclid2.in" );
	ofstream out( "euclid2.out" );

	for( in>>T; T; --T )
	{
		in>>a>>b;
		out<<gcd( a, b )<<'\n';
	}

	return EXIT_SUCCESS;
}