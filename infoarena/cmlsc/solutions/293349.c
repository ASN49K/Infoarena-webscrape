#include <stdio.h>

const int Dir[3][2] = {
	{-1, -1},
	{0, -1},
	{-1, 0}
};

int M, N;
int A[1025], B[1025];
int T[1025][1025];
char D[1025][1025];

void show_path(FILE *fo, int i, int j) {
	if (!(i*j))
		return;
	show_path(fo, i + Dir[(int)D[i][j]][0], j + Dir[(int)D[i][j]][1]);
	if (!D[i][j]) 
		fprintf(fo, "%d ", A[i]);
}

int main(int argc, char *argv[]) {
	int i, j;

	FILE *fi = fopen("cmlsc.in", "r");
	fscanf(fi, "%d %d", &M, &N);
	for (i = 1; i <= M; ++i)
		fscanf(fi, "%d", A+i);
	for (i = 1; i <= N; ++i)
		fscanf(fi, "%d", B+i);
	fclose(fi);

	for (i = 1; i <= M; ++i)
		for (j = 1; j <= N; ++j) {
			if (A[i] == B[j]) {
				T[i][j] = T[i-1][j-1] + 1;
				D[i][j] = 0;
			} else if (T[i-1][j] > T[i][j-1]) {
				T[i][j] = T[i-1][j];
				D[i][j] = 2;
			} else {
				T[i][j] = T[i][j-1];
				D[i][j] = 1;
			}
		}
	
	FILE *fo = fopen("cmlsc.out", "w");
	fprintf(fo, "%d\n", T[M][N]);
	show_path(fo, M, N);
	fprintf(fo, "\n");
	fclose(fo);

	return 0;
}

