#include <fstream>

int main() {
	std::ifstream fin("nim.in");
	std::ofstream fout("nim.out");
	int t, n, c;
	fin >> t;
	while (t--) {
		fin >> n;
		int x = 0;
		while (n--) {
			fin >> c;
			x ^= c;
		}
		fout << ((x == 0) ? "NU" : "DA") << "\n";
	}
}