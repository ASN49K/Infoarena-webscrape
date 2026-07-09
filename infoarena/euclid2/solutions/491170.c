#include <stdio.h>

#define infile "euclid2.in"
#define outfile "euclid2.out"

FILE *fin, *fout;

int cmmdc(int a, int b) {
	if  (b == 0) return a;

	return cmmdc(b, a % b);
}


int main() {
	int i, n, a, b;
	fin = freopen(infile, "r", stdin);
	fout = freopen(outfile, "w", stdout);

	scanf("%d", &n);	
	for (i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", cmmdc(a,b));
	}

	return 0;
}
