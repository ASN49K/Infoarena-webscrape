#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int euclid2(long a, long b)
{
	int i;
	long c = a > b ? a : b;
	long d, e;
	long cmmdc = 1;
	for (i = 2; i <= sqrt(c); i++)
	{
		d = a;
		e = b;
		while (d%i == 0 && e%i == 0)
		{
			cmmdc *= i;
			d = d / i;
			e = e / i;
		}
	}
	return cmmdc;
}

int main()
{
	int i, t;
	long a, b;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin >> t;

	for (i = 0; i < t; i++)
	{
		fin >> a >> b;
		fout << euclid2(a, b) << "\n";
	}

	fout.close();
	fin.close();
	return 0;
}
