#include <fstream>
using namespace std;

int gcd(int a, int b) {
	int r = 0;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int T;
	fin >> T;
	for (int i = 1; i <= T; ++i) {
		int a, b;
		fin >> a >> b;
		fout << gcd(a, b) << '\n';
	}
	return 0;
}