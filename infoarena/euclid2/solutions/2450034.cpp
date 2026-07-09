#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b) {
	
	if (!b)
		return a;
	return cmmdc(b, a % b);
}

int main() {
	int t, a, b;
	fin >> t;
	for (int i = 0; i < t; ++i) {
		fin >> a >> b;
		fout << cmmdc(a, b) << endl;
	}

	//system("pause");
	return 0;
}