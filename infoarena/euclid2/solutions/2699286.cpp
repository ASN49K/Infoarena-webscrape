#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long n, a, b;

int cmmdc(long long a, long long b)
{
	if (!b)
		return a;
	return cmmdc(b, a % b);
}

int main()
{
	fin >> n;

	for (int i = 1; i <= n; i++)
	{
		fin >> a >> b;

		fout << cmmdc(a, b) << endl;
	}
}