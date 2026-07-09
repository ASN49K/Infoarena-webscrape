#include <fstream>

using namespace std;

int gcd(const int a, const int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int tests;
	in >> tests;
	for (; tests > 0; --tests) {
		int a, b;
		in >> a >> b;
		out << gcd(a, b) << "\n";
	}
	return 0;
}
