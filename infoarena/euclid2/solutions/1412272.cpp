#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline int gcd(int x, int y) {
	if(!y)
		return x;
	return gcd(y, x % y);
}

int main() {
	int t;
	fin >> t;
	while(t -- ) {
		int x, y;
		fin >> x >> y;
		int aux = gcd(x, y);
		assert(aux == __gcd(x, y));
		fout << aux << '\n';
	}
}
