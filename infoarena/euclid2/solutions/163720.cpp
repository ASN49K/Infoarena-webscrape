#include <fstream.h>

long T, x, y;

int cmmdc( long a, long b )
{
	if( !a )return b;
	if( !b )return a;
	else
	{
		while( a != b )
		{
			if( a > b ) a -= b;
			else b -= a;
		}
	}
	return a;
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin >> T;
	fin.close();
	for( long i; i <= T; i++ )
	{
		fin >> x >> y;
		fout << cmmdc( x, y ) << '\n';
	}
	return 0;
}