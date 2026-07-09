#include <fstream>

using namespace std;

int a,b,n,i;

int cmmdc( int a, int b)
{
	if( a == b )
		return a;
	else if( a > b )
		return cmmdc( a - b, b );
	else
		return cmmdc( b - a, a );
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	f >> n;
	
	for( i = 1; i <= n; i++)
	{
		f >> a >> b;
		g << cmmdc( a, b ) << "\n";
	}
	f.close();
	g.close();
	
	return 0;
}