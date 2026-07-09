#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int comonDivider(int a, int b)
{
	int remainder = 1;
	while (remainder != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int main()
{
	int numberOfTests, a, b;
	fin >> numberOfTests;
	for (int i = 1; i <= numberOfTests; i++)
	{
		fin >> a >> b;
		fout << comonDivider(a, b) << "\n";
	}
	return 0;
}