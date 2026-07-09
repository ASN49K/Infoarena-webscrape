#include <cstdlib>
#include <fstream>

/*
 *
 */
using namespace std;
inline int gcd( int a, int b )
{
	int r;
	while( b )
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main( void )
{
	int N, a, b;
	ifstream in( "euclid2.in" );
	ofstream out( "euclid2.out" );
	for( in>>N; N; --N )
	{
		in>>a>>b;
		out<<gcd( a, b )<<"\n";
	}
	return EXIT_SUCCESS;
}