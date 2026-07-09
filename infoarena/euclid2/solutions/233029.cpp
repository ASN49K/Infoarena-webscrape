#include <fstream>
using namespace std;

int Cmmdc(int a, int b);

int main()
{
	int x, y, i, t;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin >> t;
	for ( i = 0; i < t; i++)
	{
	    fin >> x >> y;
		fout << Cmmdc(x, y) << '\n';
	}
    fout.close();
	fin.close();
	return 0;
}

int Cmmdc(int a, int b)
{
	if ( b == 0) return a;
		int rest;
		do
		{
		  rest = a % b;
		  a = b;
		  b = rest;
		} while( rest);

		return a;
}
