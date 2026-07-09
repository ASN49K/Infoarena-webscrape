// Infoarena.cpp : Defines the entry point for the console application.
//

#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned long euclid(unsigned long a, unsigned long b)
{
	if (!b)
		return a;
	euclid(b, a%b);
}

int main()
{
	unsigned long x, y, n;
	fin >> n;
	for (unsigned long i = 0; i < n; i++)
	{
		fin >> x >> y;
		fout << euclid(x, y)<<"\n";
	}
    return 0;
}

