#include <fstream>

int main() {
	std::ifstream fin("nim.in");
	std::ofstream fout("nim.out");
	int nrt, nrn, nri, val;
	fin >> nrt;
	while (nrt--) {
		fin >> nrn;
		val = 0;
		for (int index = 0; index < nrn; index++) {
			fin >> nri;
			val ^= nri;
		}
		if (val) {
			fout << "DA\n";
		}
		else {
			fout << "NU\n";
		}
	}
}