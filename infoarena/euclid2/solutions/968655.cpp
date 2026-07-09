#include <fstream>
#include "Algoritmi_1.h"

long AlgoritmulEuclid (long a, long b)
{
	if (b == 0)
		return a;
	return AlgoritmulEuclid(b, a%b);
}

void AlgoritmulLuiEuclid ()
{
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");
	long n, a, b;

	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b;
		fout << AlgoritmulEuclid(a, b)<<"\n";
	}
	fin.close();
	fout.close();
}

int main ()
{
	AlgoritmulLuiEuclid();
	return 0;
}