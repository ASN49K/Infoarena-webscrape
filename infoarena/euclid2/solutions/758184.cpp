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
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d\n", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	return 0;
}