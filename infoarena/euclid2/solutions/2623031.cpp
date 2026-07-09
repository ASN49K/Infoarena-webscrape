#include <iostream>
#include <fstream>

std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");
int n;
int a, b , r;
int main() {
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a >> b;
		if (a < b) {
			int aux = a;
			a = b;
			b = aux;
		}
		r = a % b;
		while (r) {
			a = b;
			b = r;
			r = a % b;
		}
		fout << b << "\n";
	}

	return 0;
}
