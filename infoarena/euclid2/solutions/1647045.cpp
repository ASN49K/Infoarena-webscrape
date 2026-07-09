// euclid2.cpp : Defines the entry point for the console application.
//

#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
	int rez = -1;
	while (a && b)
	{
		if (a >= b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	if (a)
		rez = a;
	else
		rez = b;
	return rez;
}

int main() {
	int a, b, len;
	fin >> len;
	for (int i = 1;i <= len;i++)
	{
		fin >> a >> b;
		fout << euclid(a, b) << '\n';
	}
	return 0;
}
