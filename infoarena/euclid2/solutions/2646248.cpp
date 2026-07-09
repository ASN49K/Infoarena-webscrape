#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long CMMDC(long a, long b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else if (a > b)
		return CMMDC(a % b, b);
	else
		return CMMDC(a, b % a);
}

int main()
{
	long T, nr1, nr2;
	fin >> T;
	for (int i = 1; i <= T; ++i)
	{
		fin >> nr1 >> nr2;
		fout << CMMDC(nr1, nr2) << endl;
	}
	return 0;
}