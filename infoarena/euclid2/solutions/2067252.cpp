#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int x, int y) {
	if (!y) return x;
	else return cmmdc(y, x%y);
}

void main() {
	int t, a, b;
	f >> t;
	for (; t; --t) {
		f >> a >> b;
		g << cmmdc(a, b) << "\n";
	}
}