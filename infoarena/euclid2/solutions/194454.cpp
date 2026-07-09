/* Algoritmul lui Euclid pentru aflarea celui mai mare divizor comun a 2 numere */
#include <fstream>
int T, a, b;

int gcd1( int a, int b )
{
	int r;
	while( b )
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int gcd( int a, int b )
{
	return (b != 0) ? gcd( b, a%b ) : a;
}

int main()
{
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	fin >> T;
	for( ; T; T-- )
	{
		fin >> a >> b;
		fout << gcd1( a, b ) << '\n';
	}
	fin.close(); fout.close();
	return 0;
}
