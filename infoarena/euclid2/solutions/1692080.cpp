#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int x, int y)
{
	int r = x%y;

	while (r)
	{
		x = y;
		y = r;
		r = x%y;
	}
	return y;
}

int t, a, b;

int main()
{
	fin >> t;
	while (t--)
	{
		fin >> a >> b;
		fout << cmmdc(a, b) << '\n';
	}
	return 0;
}