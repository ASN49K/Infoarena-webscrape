#include <fstream>
#include <cstdlib>

using namespace std;
typedef unsigned int uint;

inline uint gcd( uint x, uint y )
{
	if( !y )
		return x;
	return gcd( y, x%y );
}
int main( void )
{
	uint T, x, y;
	ifstream in( "euclid2.in" );
	ofstream out( "euclid2.out" );
	
	for( in>>T; T; --T )
	{
		in>>x>>y;
		out<<gcd( x, y )<<'\n';
	}	
	return EXIT_SUCCESS;
}
