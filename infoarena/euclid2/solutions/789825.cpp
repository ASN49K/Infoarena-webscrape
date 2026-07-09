#include <fstream>

std::ifstream fin;
std::ofstream fout;

int gcd( int x, int y );

int main(int argc, char const *argv[])
{
	int N, x, y;
	fin.open("euclid2.in");
	fin >> N;
	fout.open("euclid2.out");
	for( int i = 0; i < N; ++i )
	{
		fin >> x >> y;
		fout << gcd(x, y) << '\n';
	} 
	return 0;
}

int gcd( int x, int y )
{
	return y == 0 ? x : gcd(y, x % y);
}