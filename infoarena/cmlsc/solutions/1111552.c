#include <stdio.h>

#define NMax 260
int M, N, A[NMax], B[NMax];

void cmlsc (int *a, int m, int *b, int n) {	
int i, j, min, size, res[NMax];

	size=0;
	min=1;
	
	for (i = 1; i<=n; ++i) {
		j = min;
		do {
			if (b[i] == a[j]) {
				++size;
				res[size] = b[i];
				min = j;
				break;
			}
			++j;
		}while (j<=m);
	}
	
	printf("%d\n",size);
	for (i = 1; i<=size; ++i)
		printf("%d ",res[i]);
		
	printf("\n");
}


int main (void) {
	
	int i;
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d", &M, &N); 
	
	for (i = 1; i<=M; ++i) {
		scanf("%d",&A[i]);
	}
		
	for (i = 1; i<=N; ++i) {
		scanf("%d",&B[i]);
	}
	
	cmlsc (A,M,B,N);

return 0;
}