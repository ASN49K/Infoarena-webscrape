#include <stdio.h>
#define DIM 1026

int n,m,i,j,k;
int A[DIM],B[DIM],S[DIM][DIM],sir[DIM];

int max(int a, int b) {
	return a>b?a:b;
}

int main(){
	
	FILE *f = fopen("cmlsc.in","r");
	FILE *g = fopen("cmlsc.out","w");
	
	fscanf(f,"%d%d",&n,&m);
	
	for (i=1; i<=n; i++)
		fscanf(f,"%d",&A[i]);
	
	for (i=1; i<=m; i++)
		fscanf(f,"%d",&B[i]);
	
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if (A[i]==B[j])
				S[i][j] = S[i-1][j-1] + 1;
			else
				S[i][j] = max(S[i-1][j],S[i][j-1]);
	
	fprintf(g,"%d\n",S[n][m]);
	
	for (i=n, j=m; i; ) {
		if (A[i]==B[j]) {
			sir[++k] = A[i];
			i--;
			j--;
		}
		else 
			if (S[i-1][j] < S[i][j-1])
				j--;
			else
				i--;
	}

	for (i=k; i; i--)
		fprintf(g,"%d ",sir[i]);
	
	fclose(f);
	fclose(g);
	
	return 0;
}
