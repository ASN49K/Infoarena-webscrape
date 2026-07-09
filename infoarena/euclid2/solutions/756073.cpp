#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main () {
	int t, a, b, c;
	freopen ("euclid2.in", "rt", stdin);
	freopen ("euclid2.out", "wt", stdout);
	for (scanf ("%d", &t); t; -- t) {
		scanf ("%d%d", &a, &b);
		while (a) {
			c = b % a;
			b = a;
			a = c;
		}
		printf ("%d\n", b);
	}
	return 0;
}
