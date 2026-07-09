#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gdc(int a, int b) {
	int r = 1;
	while (r) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int n, a, b;
	fin >> n;
	while (n--) {
		fin >> a >> b;
		fout << gdc(a, b) << '\n';
	}

	fout.close();
	return 0;
}