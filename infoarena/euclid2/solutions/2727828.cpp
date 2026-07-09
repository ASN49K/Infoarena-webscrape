#include <fstream>
#include <iostream>

int CMMDC(int a, int b) {
	int r;

	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");

	unsigned long t;
	fin >> t;

	int a, b;

	for (int i = 0; i < t; ++i) {
		fin >> a >> b;
		fout << CMMDC(a, b) << '\n';
	}

	fin.close();
	fout.close();

	return 0;
}