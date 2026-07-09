#include <stdio.h>

#define INPUT "euclid2.in"
#define OUTPUT "euclid2.out"
#define MAX 100000
#define SUCCESS 0

int cmmdc(int a, int b) {
	if (b == 0 && a != 0) {
		return a;
	} else if (b == 1) {
		return 1;
	} else if (a < b) {
		return cmmdc(b, a);
	} else {
		return cmmdc(b, a % b);
	}
}

int main() {
	freopen(INPUT, "r", stdin);
	freopen(OUTPUT, "w", stdout);
	int n, a, b;

	scanf("%d\n", &n);
	while (n-- > 0) {
		scanf("%d %d\n", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	fclose(stdin);
	fclose(stdout);
	return SUCCESS;
}
