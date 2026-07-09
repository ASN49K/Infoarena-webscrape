#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long CMMDC(long a, long b)
{
	int r = a % b;
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	int T, nr1, nr2;
	fin >> T;
	for (int i = 1; i <= T; ++i)
	{
		fin >> nr1 >> nr2;
		fout << CMMDC(nr1, nr2) << endl;
	}
}