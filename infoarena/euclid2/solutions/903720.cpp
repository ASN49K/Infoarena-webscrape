#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int x, int y) {
	if (!y) return x;
	return cmmdc(y, x%y);
}

int main() {
	int n, a, b;
	in >> n;

	while (n) {
		n--;
		in >> a;
		in >> b;

		out << cmmdc(a, b) << endl;
	}

	return 0;
}