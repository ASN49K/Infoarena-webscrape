#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
	while (b)
	{
		int r = a% b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int T, a, b;
	fin >> T;
	for (int i = 1; i <= T; i++)
	{
		fin >> a >> b;
		if (i == T)
			fout << cmmdc(a, b);
		else
			fout << cmmdc(a, b) <<"\n";
	}
}