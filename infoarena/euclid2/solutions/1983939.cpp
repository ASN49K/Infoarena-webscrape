#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long i, n, a, b, c;
int cmmd(long long a, long long b)
{
	long long k;
	while (b != 0)
	{
		k = b;
		b = a % b;
		a = k;
	}
	return a;
}
int main()
{
	fin >> n;
	for (i = 1; i <= n; i++)
	{
		fin >> a;
		fin >> b;
		fout << cmmd(a, b) <<'\n';

	}
	return 0;
}
