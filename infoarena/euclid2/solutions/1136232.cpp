#include <fstream>
#include <iostream>
#include <cstdio>
#include <algorithm>

#define ARHIVA

using namespace std;

int N;

int gcd(int x, int y) {
	if (y) {
		return gcd(y, x % y);
	}
	return x;
}

int main() {
#ifndef ARHIVA
	freopen("input.txt", "r", stdin);
#else 
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
#endif
	int i, x, y;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> x >> y;
		cout << gcd(max(x, y), min(x,y)) << '\n';
	}
#ifndef ARHIVA
	while (1);
#endif
}