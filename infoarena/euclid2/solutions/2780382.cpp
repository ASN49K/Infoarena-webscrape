#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int t;
	fin >> t;

	while (t--)
	{
		int a, b;
		fin >> a >> b;

		while (a % b)
		{
			int r = a % b;
			a = b;
			b = r;
		}

		fout << b << '\n';
	}
}

