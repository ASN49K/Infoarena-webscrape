#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int n, a, b;
	fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> a >> b;

		while (b % a)
		{
			int r = b % a;
			a = b;
			b = r;
		}

		fout << b << '\n';
	}
}
