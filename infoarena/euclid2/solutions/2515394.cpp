#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	int nr, var1, var2;
	fin >> nr;
	for (int i = 1; i <= nr; i++)
	{
		fin >> var1 >> var2;
		fout << gcd(var1, var2) << '\n';
	}
}