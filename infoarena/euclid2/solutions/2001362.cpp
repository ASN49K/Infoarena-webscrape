#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int t, x, y;
	fin >> t;
	for (int i = 0; i < t; i++) {
		fin >> x >> y;
		fout << euclid(x, y) << "\n";
	}
	return 0;
}