#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

//#define _debug
int main() {
#ifndef _debug
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		int nr;
		scanf("%d", &nr);
		long sum = 0;
		for (int i = 0; i < nr; i++) {
			long tmp;
			scanf("%ld", &tmp);
			sum ^= tmp;
		}
		if (sum)
			printf("DA");
		else
			printf("NU");
	}
}