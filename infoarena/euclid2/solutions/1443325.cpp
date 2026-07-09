#include <cstdio>
#include <cassert>
#define _submit
#ifdef _submit
#define InFile "euclid2.in"
#define OutFile "euclid2.out"
#else
#define InFile "fis.in"
#define OutFile "fis.out"
#endif

typedef unsigned int uint;

uint cmmdc(uint a, uint b) {
	while (b) {
		uint aux = a;
		a = b;
		b = aux%b;
	}
	return a;
}

int main() {
	assert(freopen(InFile, "r", stdin));
	assert(freopen(OutFile, "w", stdout));
	uint T;
	scanf("%u", &T);
	while (T--) {
		uint a, b;
		scanf("%u%u", &a, &b);
		printf("%u\n", cmmdc(a, b));
	}
	return 0;
}