#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

long long cmmdc (long long a, long long b) {
	long long c;
	while (a) {
		c = b % a;
		b = a;
		a = c;
	}
	return c;
}

int main () {
	int t, a, b, c;
	freopen ("euclid2.in", "rt", stdin);
	freopen ("euclid2.out", "wt", stdout);
	for (scanf ("%d", &t); t; -- t) {
		scanf ("%d%d", &a, &b);
		printf ("%d\n", cmmdc (a, b));
	}
	return 0;
}
