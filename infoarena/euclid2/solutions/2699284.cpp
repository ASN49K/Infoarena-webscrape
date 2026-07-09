#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
	while (b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int n, a, b;
	
	fin >> n;

	for (int i = 1; i <= n; i++)
	{
		fin >> a >> b;

		fout << cmmdc(a, b) << endl;
	}
}