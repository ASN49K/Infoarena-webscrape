#include <stdio.h>
#define file_in "euclid2.in"
#define file_out "euclid2.out"


int cmmdc(int a, int b) {
	if (b==0) return a;
	return cmmdc(b, a % b);
}

int main() {
	int i, a, b;

	freopen(file_in, "r", stdin);
	freopen(file_out, "w", stdout);

	for (scanf("%d", &i); i>0; i--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	return 0;
}
