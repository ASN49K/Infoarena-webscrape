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
	while (fin >> a) {
		fin >> b;
		fout << cmmdc(a, b) << endl;
	}

	//system("pause");
	return 0;
}