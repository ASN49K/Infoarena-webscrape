#include <fstream>

using namespace std;

int gcd (int u, int v){
	if (u < 0) {
		u = (1 + ~u);
	}
	if (u == v) {
		return u;
	}
	if (u && v) {
		int k, p = 1;
		for (k = 0; ! ((p & u) ||  (p & v)) && k < 31; ++ k, p <<= 1);
		v >>= k;
		u >>= k;
		return gcd (u - v, v) << k;
	}
	else {
		return (u + v);
	}
}

int main() {
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	int t, a, b;
	for (f>>t; t; -- t) {
		f >> a >> b;
		g << gcd(a, b) << '\n';
	}
	return 0;
}