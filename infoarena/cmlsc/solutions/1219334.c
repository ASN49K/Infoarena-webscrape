#include <stdio.h>
#include <stdlib.h>

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAX(a,b) (((a)>(b))?(a):(b))

void cmlsc(int M, int N, int *a, int *b, FILE *f){
	int **lcs,i,j,k;
	lcs = (int**)calloc(M+1,sizeof(int*));
	for(i = 0; i <= M; i++){
		lcs[i] = (int*)calloc(N+1,sizeof(int));
	}
	
	for(i=1; i <= M; i++){
		for(j=1; j <= N; j++){
			if(a[i-1] == b[j-1]){
				lcs[i][j] = lcs[i-1][j-1] + 1;
			} else {
				lcs[i][j] = MAX(lcs[i][j-1], lcs[i-1][j]);
			}
		}
	}
	k = lcs[M][N];
	fprintf(f, "%d\n", lcs[M][N]);
	for(i=M-1, j=N-1; i || j; ){
		if(a[i] == b[j]){
			fprintf(f, "%d", a[i]);
			k--;
			if(i) i--;
			if(j) j--;
			if(k) fprintf(f, " ");
		} else {
			if(j == 0){
				i--;
			} else {
				j--;
			}
		}
	}
}

int main(){
	int M,N, *a, *b,i;
	FILE *in, *out;
	
	in = fopen(FIN, "rt");
	out = fopen(FOUT, "wt");
	
	fscanf(in, "%d%d", &M, &N);
	a = (int*)calloc(M,sizeof(int));
	b = (int*)calloc(N,sizeof(int));
	
	for(i=0; i < M; i++){
		fscanf(in, "%d", &a[i]);
	}
	
	for(i=0; i < N; i++){
		fscanf(in, "%d", &b[i]);
	}
	
	cmlsc(M,N,a,b,out);

	free(a);
	free(b);
	return 0;
}

