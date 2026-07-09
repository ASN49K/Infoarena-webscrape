#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b);

int main() {
	int T;
	int a, b;

	for (int i = 1; i <= T; ++i) {
		fin >> a >> b;
		fout << gcd(a, b);
	}
	return 0;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}