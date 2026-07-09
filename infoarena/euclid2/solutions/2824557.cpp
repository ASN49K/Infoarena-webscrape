#include <fstream>

int main() {
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");

	int n;
	fin >> n;

	while (n--) {
		int a, b;
		fin >> a >> b;

		int t;
		while (b) {
			t = b;
			b = a % b;
			a = t;
		}

		fout << a << std::endl;
	}
	return 0;
}
