#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b);

int main() {
	int T;
	int a, b;
	fin >> T;
	for (int i = 1; i <= T; ++i) {
		fin >> a >> b;
		fout << gcd(a, b) << '\n';
	}
	return 0;
}

int gcd(int a, int b) {
	int k;
	while (b != 0) {
		k = a;
		a = b;
		b = k % b;
	}
	return a;
}