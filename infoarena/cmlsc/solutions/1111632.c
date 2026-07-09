#include <stdio.h>

#define NMax 1024
#define max(a,b) ((a>b) ? a : b)

int M, N, A[NMax], B[NMax], res[NMax], D[NMax][NMax], size;

void cmlsc (int *a, int m, int *b, int n) {	
int i, j, aux;
	for (i=1; i<=m; ++i) 
		for (j=1; j<=n; ++j)
			if (a[i]==b[j]) D[i][j] = 1 + D[i-1][j-1];
			else D[i][j] = max(D[i-1][j],D[i][j-1]);
			
	size = D[m][n];
	aux = size;
	printf("%d\n",size);
	
	for (i=m, j=n; aux; )
		if (a[i]==b[j]) {
			res[aux] = a[i];
			--aux;
			--i;
			--j;
			}
		else if (D[i-1][j] > D[i][j-1])
				i--;
			else
				j--;
				
	for (i=1; i<=size; ++i)
		printf("%d ",res[i]);
}


int main (void) {
	
	int i;
	size=0;
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d", &M, &N); 
	
	for (i = 1; i<=M; ++i) {
		scanf("%d",&A[i]);
	}
		
	for (i = 1; i<=N; ++i) {
		scanf("%d",&B[i]);
	}
	
	for (i=0;i<=M;++i)
		D[i][0] = 0;
	for (i=0;i<=N;++i)
		D[0][i] = 0;
	
	cmlsc (A,M,B,N);

return 0;
}