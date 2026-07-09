#include <iostream>
#include <fstream>
#include <stdint.h>

int main() {
	std::ifstream fin("nim.in");
	std::ofstream fout("nim.out");

	int32_t t;
	fin >> t;

	for(int32_t i = 0; i != t; ++i) {
		int32_t n;
		fin >> n;

		int32_t sum = 0;
		for(int32_t j = 0; j != n; ++j) {
			int32_t val;
			fin >> val;
			sum ^= val;
		}

		if(sum) {
			fout << "DA\n";
		} else {
			fout << "NU\n";
		}
	}

	fin.close();
	fout.close();

	return 0;
}