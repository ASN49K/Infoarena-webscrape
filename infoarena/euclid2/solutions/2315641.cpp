#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

inline int gcd(int a, int b) {

	for (int rem; b; rem = a % b, a = b, b = rem);
	return a;
}

int main() {

	int Q;
	fin >> Q;

	for (; Q; --Q) {

		int a, b;
		fin >> a >> b;

		fout << gcd(a, b) << '\n';
	}
}