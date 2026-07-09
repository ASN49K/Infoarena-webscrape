#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int Cmmdc( int x, int y);
int main()
{
	int t, a, b;
	fin >> t;
	for( int i = 0; i < t; ++i )
	{
		fin >> a >> b;
		fout << Cmmdc( a, b ) << ' ';
	}

	fin.close();
	fout.close();
	return 0;
}

int Cmmdc(int x, int y)
{
		fin >> x >> y;
		if( y == 0 ) return x;
		
		int rest;
		do
		{
			rest = x % y;
			x = y;
			y = rest;
		}while(rest);
	return x;
		
	}

