#include <fstream>
#include <cstdlib>

using namespace std;
inline int gcd( int a, int b )
{
	int r=b;
	while( r )
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
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
