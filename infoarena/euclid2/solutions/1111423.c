#include <stdio.h>

int T, A, B;

int euclid (int a, int b) {	
	if (b == 0) return a;
	else return euclid(b, a % b);
}

int main (void) {
	int res;
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	for (scanf("%d", &T); T; --T) {
		scanf("%d %d",&A, &B);
		if (A < B ) {
			res = A;
			A = B;
			B = res;
		}
		res = euclid(A,B);
		printf("%d\n",res);
	}

return 0;
}