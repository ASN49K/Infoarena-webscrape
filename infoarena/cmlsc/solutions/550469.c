#include <stdio.h>

int Rez[256], S[256], T[256], L[256][256], len;
int N, M;

void cmlsc(int *S, int *T)
{
	int i, j;
	for (i=1; i<=M; ++i)
		for (j=1; j<=N; ++j)
			if (S[i] == T[j])
				L[i][j] = L[i-1][j-1]+1;
			else if (L[i][j-1] > L[i-1][j])
				L[i][j] = L[i][j-1];
			else
				L[i][j] = L[i-1][j];
	for (i=M, j=N; i;)
		if (S[i] == T[j]) {
			Rez[++len] = S[i];
			 --i;
			 --j;
		}
		else if (L[i][j-1] > L[i-1][j])
			--j;
		else
			--i;
}

int main(argc, argv)
int argc;
char *argv[];
{
	int i;
	FILE *fin = fopen("cmlsc.in", "r");
	fscanf(fin, "%d %d", &M, &N);
	for (i=1; i<=M; ++i)
		fscanf(fin, "%d", &S[i]);
	for (i=1; i<=N; ++i)
		fscanf(fin, "%d", &T[i]);
	fclose(fin);
	cmlsc(S, T);
	FILE *fout = fopen("cmlsc.out", "w");
	fprintf(fout, "%d\n", len);
	for (i=len; i>=1; --i)
		fprintf(fout, "%d ", Rez[i]);
	fclose(fout);
	return 0;
}
