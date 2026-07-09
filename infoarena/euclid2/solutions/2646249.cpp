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
	long T, a, b;
	fin >> T;
	for (int i = 1; i <= T; ++i)
	{
		fin >> a >> b;
		fout << CMMDC(a, b) << endl;
	}
	return 0;
}