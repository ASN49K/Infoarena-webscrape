#include <fstream>
#include <iostream>

int main() {
	std::ifstream fin("euclid2.in");
	std::ofstream fout("euclid2.out");

	int n;
	fin >> n;

	while (n--) {
		int a, b;
		fin >> a >> b;
		std::cout << a << " " << b << std::endl;

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
