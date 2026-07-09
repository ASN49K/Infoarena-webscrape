#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, a, b;

unsigned int count_trailing_zeros(unsigned int x) {
	int count = 0;
	while ((x & 1) == 0) {
		x >>= 1;
		count++;
	}
	return count;
}

int gcd(int a, int b) {
	if (!a || !b) {
		return a | b;
	}

	unsigned int shift = count_trailing_zeros(a | b);
	a >>= count_trailing_zeros(a);
	do {
		b >>= count_trailing_zeros(b);
		if (a > b) {
			swap(a, b);
		}
		b -= a;
	} while (b);

	return a << shift;
}

int main()
{
	int	ans;
	fin >> T;

	while (T--) {
		fin >> a >> b;
		fout << gcd(a, b) << "\n";
	}

	return 0;
}