#include<stdio.h>

int cmmdc(int a, int b) {
	 int r = b % a;
	 while(r != 0) {
	 	a = b;
	 	b = r;
	 	r = b % a;
	 }
	 return b;
}

int main() {
	int n, a, b;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &n);

	for(; n; n--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	return 0;
}