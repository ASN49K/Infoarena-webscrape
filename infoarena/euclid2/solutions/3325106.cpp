#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int x, int y) {
	if(!y) { return x; }
	return gcd(y, x % y);
}

int main() {

	int t;
	in >> t;

	while(t--) {
		int x, y;
		in >> x >> y;
		out << gcd(x, y) << '\n';
	}

	return 0;
}