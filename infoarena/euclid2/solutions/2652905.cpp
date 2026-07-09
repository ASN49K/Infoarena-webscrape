#include <iostream>
#include <fstream>
using namespace std;

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int T;
	fin >> T;

	for (int i = 0; i < T; ++i) {
		int a, b;
		fin >> a >> b;
		fout << gcd(a, b) << "\n";
	}

	return 0;
}