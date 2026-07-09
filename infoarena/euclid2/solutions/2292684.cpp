#include <iostream>
#include <fstream>
using namespace std;

int func(int a, int b)
{
	if (a == b) return a;
	return func(b, a % b);
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int T, a, b, r;
	fin >> T;

	for (int i = 1; i <= T; i++)
	{
		fin >> a >> b;
		func(a, b);
	}

	fout.close();

	//system("pause");
	return 0;
}