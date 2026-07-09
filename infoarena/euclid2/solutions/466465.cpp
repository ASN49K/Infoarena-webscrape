#include <stdio.h>

int T, A, B;

int CMMDC (int a, int b) {
	if (a % b)
		return CMMDC (b, a % b);
	else
		return b;	
}

int main () {
	
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.out", "w", stdout);
	
	scanf ("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf ("%d%d", &A, &B);		
		printf ("%d\n", CMMDC(A, B));
	}
	
	return 0;
}
