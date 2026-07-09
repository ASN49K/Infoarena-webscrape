#include <fstream>
using namespace std;

int euc(int a, int b)
{
	if (!b) return a;
	else return euc(b, a%b);
}

int main()
{
	ifstream  fin("euclid2.in");
	ofstream fout("euclid2.out");
	long int t;
	long long unsigned int a, b;
	fin >> t;
	for (int i = 0; i < t; i++)
	{
		fin >> a >> b;
		fout << euc(a, b) << '\n';
	}
}