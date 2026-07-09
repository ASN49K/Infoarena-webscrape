#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
	int r = 0;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int nr = 0, a, b;
	fin >> nr;
	for (int i = 0; i < nr; ++i)
	{
		fin >> a >> b;
		fout << euclid(a, b) << '\n';
	}
	return 0;
}