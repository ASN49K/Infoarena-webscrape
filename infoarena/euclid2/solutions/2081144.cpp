#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
	while (a * b) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}

	return a + b;
}

int main()
{
	int t, a, b;
	ifstream fin("euclid2.in", ifstream::in);
	ofstream fout("euclid2.out", ofstream::out);
	fin >> t;
	for (int i = 0; i < t; ++i) {
		fin >> a >> b;
		fout << euclid(a,b) << endl;
	}

	return 0;
}
