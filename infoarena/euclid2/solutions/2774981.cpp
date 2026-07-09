/* [A][M][C][B][N] / [K][R][I][P][6][8] */
#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
// Global variables
const char sp = ' ', nl = '\n';
const int MOD = 777013; // 666013 998244353 1000000007
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void solve() {
	int a, b;
	fin >> a >> b;
	while (b) a %= b, swap(a, b);
	fout << a << nl;
}

int main() {
	int t;
	fin >> t;
	while (t--) {
		solve();
	}
}