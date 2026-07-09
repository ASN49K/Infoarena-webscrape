#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int cmmdc (int a, int b)
{
	return (b == 0) ? a : cmmdc (b, a%b);
}

int main()
{
	ifstream fin ("euclid2.in");
	ofstream fout ("euclid2.out");

	int n, a, b;
	fin >> n;
	while (fin >> a >> b)
		fout << cmmdc (a, b) << '\n';

	fout.close();
	return EXIT_SUCCESS;
}
