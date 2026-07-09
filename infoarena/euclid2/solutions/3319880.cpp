#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a, b,t;

int gcd(int x, int y) {
	if (x < y) {
		swap(x, y);
	}
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main()
{
	in >> t;
	for (int i = 1; i <= t; i++) {
		in >> a >> b;
		out << gcd(a, b)<<'\n';
	}

	return 0;
}