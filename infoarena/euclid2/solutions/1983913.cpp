#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long i, n, a, b, c;
int cmmd(long a, long b)
{
	if (b == 0)
		return a;
	else 
	return cmmd(b,a%b);
}
int main()
{
	fin >> n;
	for (i = 1; i <= n; i++)
	{
		fin >> a;
		fin >> b;
		fout << cmmd(a, b) << endl;

	}
	return 0;
}