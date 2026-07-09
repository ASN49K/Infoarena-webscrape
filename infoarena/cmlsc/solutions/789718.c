#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int len;
	int dir;
} emat;

void rec(emat* dyn, int n, int i, int j, FILE* fis, int* sir) {
	if((i != 0) && (j != 0)) {
		if(dyn[(n+1)*i + j].dir == 2) {
				rec(dyn, n, i-1, j-1, fis, sir);
			}
		else if( dyn[(n+1)*i + j].dir == 1) {
				rec(dyn, n, i, j-1, fis, sir);
			}
		else {
				rec(dyn, n, i-1, j, fis, sir);
			}
		if( dyn[(n+1)*i + j].dir == 2) {
			fprintf(fis,"%i ", sir[i-1]);
		}
	}
}

int main() {
	int M, N, i, j;
	int *mv, *nv;
	emat *dyn;
	FILE* fis;
	
	fis = fopen("cmlsc.in", "rt");
	fscanf(fis, "%i %i", &M, &N);
	mv = (int*)calloc(M, sizeof(int));
	nv = (int*)calloc(N, sizeof(int));
	for(i = 0; i < M; i ++)
		fscanf(fis, "%i", mv + i);
	for(i = 0; i < N; i ++)
		fscanf(fis, "%i", nv + i);
	fclose(fis);

	dyn = (emat*)calloc((M+1)*(N+1), sizeof(emat));
	
	for(i = 1; i <= M; i++)
		for(j = 1; j <= N; j++)
			if(mv[i-1] == nv[j-1]) {
				dyn[(N+1)*i + j].len =  dyn[(N+1) * (i-1) + j-1].len + 1;
				dyn[(N+1)*i + j].dir = 2;
			}
			else if( dyn[(N+1)*i + j-1].len > dyn[ (N+1) * (i-1) + j].len) {
				dyn[(N+1)*i + j].len = dyn[ (N+1)*i + j-1].len;
				dyn[(N+1)*i + j].dir = 1;
			}
			else {				
				dyn[(N+1)*i + j].len = dyn[(N+1)*(i-1) + j].len;
				dyn[(N+1)*i + j].dir = 3;
			}

	fis = fopen("cmlsc.out", "wt");
	fprintf(fis, "%i\n", dyn[(N+1)*(M+1)-1].len);
	rec(dyn, N, M, N, fis, mv);
	fclose(fis);
	free(dyn);
	free(nv);
	free(mv);
	return 0;
}
