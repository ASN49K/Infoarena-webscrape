#include <fstream>
using namespace std; 

ifstream in ( "euclid2.in" );
ofstream out ( "euclid2.out" );

int T;

void cmmdc ( int a, int b )
{
	int c;
	
	while ( b )
	{
		c = a % b;
		a = b;
		b = c;
	}
	
	out << a << "\n";
}

int main ()
{
	int a, b;
	
	in >> T;
	
	for ( int i = 1; i <= T; ++i )
		in >> a >> b, cmmdc ( a, b );
	
	return 0;
}
