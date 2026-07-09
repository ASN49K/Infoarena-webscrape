#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream o("euclid2.out");

int t, a, b;

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main() {

	f >> t;
	for (; t; --t) {
		f >> a >> b;
		o << gcd(a, b) << "\n";
	}
	return 0;
}