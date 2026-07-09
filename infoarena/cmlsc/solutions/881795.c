/* Cel mai lung subsir comun - vezi infoarena */
#include <stdio.h>

#define MAX 1024

int main() {
	FILE *fin, *fout;
	int i, j;
	int M, N, P;
	int a[MAX], b[MAX], c[MAX], pos[MAX];

	fin = fopen("cmlsc.in", "r");
	fout = fopen("cmlsc.out", "w");

	if (fin == NULL || fout == NULL)
		return -1;

	fscanf(fin, "%d", &M);
	fscanf(fin, "%d", &N);

	for (i = 0; i < M; i++)
		fscanf(fin, "%d", a + i);

	for (i = 0; i < N; i++)
		fscanf(fin, "%d", b + i);
#if 0
	for (i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n");

	for (i = 0; i < N; i++)
		printf("%d ", b[i]);
	printf("\n");
#endif

	P = -1;
	for (i = 0; i < M; i++) {
		for (j = (P == -1 ? 0 : pos[P] + 1); j < N; j++) {
			if (a[i] == b[j]) {
				P++;
				c[P] = a[i];
				pos[P] = j;
			}
		}
	}

	fprintf(fout, "%d\n", P + 1);

	for (i = 0; i <= P; i++)
		fprintf(fout, "%d ", c[i]);
	fprintf(fout, "\n");

	fclose(fin);
	fclose(fout);

	return 0;
}
