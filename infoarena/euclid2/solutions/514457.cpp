#include "stdio.h"

int T, A, B;

int gcd (int a, int b) {
	if (!b)
		return a;
	return gcd (b, a%b);
}

int main (void) {
	ifstream r("euclid2.in");
	ofstream w("euclid2.out");

	r>>T;
	for (; T; --T) {
		r>>A>>B;
		w<<gcd (A, B)<<"\n";
	}
	return 0;
}