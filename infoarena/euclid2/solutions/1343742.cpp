#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd_modulo(long a, long b) {
	long c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int gcd_sub(long a, long b) {
	while (b) {
		if (a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}
	return a;
}

int main() {
	int t;
	long a, b;
	fin >> t;
	for (int i = 0; i < t; i++) {
		fin >> a >> b;
		fout << gcd_modulo(a, b) << '\n';
	}
	
	fin.close();
	fout.close();
	return 0;
}
