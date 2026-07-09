#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main () {
	int t, a, b, c;
	freopen ("euclid2.in", "rt", stdin);
	freopen ("euclid2.out", "wt", stdout);
	for (cin >> t; t; -- t) {
		cin >> a >> b;
		while (a) {
			c = b % a;
			b = a;
			a = c;
		}
		cout << b << '\n';
	}
	return 0;
}
