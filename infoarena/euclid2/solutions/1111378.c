#include <stdio.h>

#define min(a,b) ((a<b) ? a : b)

int T, A, B;

void euclid (int a, int b) {
	int i;
	for (i=min(a,b); i; --i) {
		if (a%i==0 && b%i==0) {
			printf("%d\n",i);
			break;
		}
	}
}

int main (void) {
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	for (scanf("%d", &T); T; --T) {
		scanf("%d %d",&A, &B);
		euclid(A,B);
	}

return 0;
}