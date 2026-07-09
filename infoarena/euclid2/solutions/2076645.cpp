#include <fstream>

#include <vector>
#include <string>

#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b) {
	int r;

	do {
		if (b > a)
			swap(a, b);

		r = a % b;
		a = b;
		b = r;
	} while (b != 0);

	return a;
}

int main() {
	fin.sync_with_stdio(false);

	int T, a, b;
	int i;

	fin >> T;

	for (i = 0; i < T; ++i) {
		fin >> a >> b;
		fout << gcd(a, b) << '\n';
	}

	return 0;
}