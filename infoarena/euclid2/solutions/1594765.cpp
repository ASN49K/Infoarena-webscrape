#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void interschimbare(int &a, int &b)
{
	int m = b;
	b = a;
	a = m;
}

int euclid(int a, int b)
{
	int m;
	do
	{
		m = a%b;
		a = b;
		b = m;
	} while (b != 0);
	return a;
}

int main()
{
	int n, a, b, i;
	fin >> n;
	for (i = 1;i <= n;i++)
	{
		fin >> a >> b;
		if (b > a)
			interschimbare(a, b);
		fout << euclid(a, b) << endl;

	}
}