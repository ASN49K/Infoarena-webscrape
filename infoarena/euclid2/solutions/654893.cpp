#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int a, b, n;
	fin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		fin >> a >> b;
		while ( a!=b )
		{
			if ( a > b )
				a -= b;
			else b-=a;
		}
		fout << a << " ";
		fout << '\n';
		
	}
	fin.close();
		fout.close();
}