#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(long a, long b) {
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int t;
	long a, b;
	fin >> t;
	for (int i = 0; i < t; i++) {
		fin >> a >> b;
		fout << gcd(a, b) << '\n';
	}
	
	fin.close();
	fout.close();
	return 0;
}
