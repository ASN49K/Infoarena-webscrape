
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
unsigned int gcd(unsigned int m, unsigned  int n)
{
	while (m != 0)
	{
		unsigned int r = n % m;
		n = m;
		m = r;
	}
	return n;
}
int main()
{
	ifstream fin("date.in");
	ofstream fout("date.out");
	unsigned int t, v1, v2, aux;
	fin >> t;
	for (unsigned int i = 1; i <= t; i++)
	{
		fin >> v1 >> v2;
		fout << gcd(v1, v2) << "\n";
	}
} 