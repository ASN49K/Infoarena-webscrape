/// [A][M][C][B][N] ///
#include <bits/stdc++.h>
const int mod = 20173333;
const int inf = 0x3f3f3f3f;
const char sp = ' ', nl = '\n';
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int t;
	fin >> t;
	while (t--) {
		int x, y;
		fin >> x >> y;
		fout << gcd(x, y) << nl;
	}
}