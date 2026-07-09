#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Fie v un vector cu N elemente. Se numeste subsir de lungime K al vectorului v un nou vector v' = (vi1, vi2, ... viK), cu i1 < i2 < ... < iK.
 * De exemplu, vectorul v = (5 7 8 9 1 6) contine ca subsir sirurile (5 8 6) sau (7 8 1), dar nu contine subsirul (1 5).
 * Se dau doi vectori A si B cu elemente numere naturale nenule.
 * Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.
 */

/*  Relatia de recurenta:
 *
 *  lcs(xi, yj) =  0                                 ,  i = 0 or j = 0
 *                 lsc(xi-1, yi-1) + 1               ,  xi = yi
 *                 max(lsc(xi-1, yi), lsc(xi, yi-1)) ,  xi != yi
 * */


#define NMAX 1024+2
int M, N;
int A[NMAX];
int B[NMAX];

int lsc[NMAX][NMAX];

int smax = 0;
int im, jm;

void solutie_cmlsc()
{
	int i, j;

	memset(lsc[0], 0, N*sizeof(int));
	for(i = 1; i<= M; i++)
		lsc[i][0] = 0;

	for( i = 1; i <= M; i++ ) {
		for( j = 1; j <= M; j++ ) {
			if(A[i] == B[j])
				lsc[i][j] = lsc[i-1][j-1]+1;
			else
				lsc[i][j] = (lsc[i-1][j]>lsc[i][j-1])?lsc[i-1][j]:lsc[i][j-1];
			if(smax < lsc[i][j]) {
				smax = lsc[i][j];
				im = i; jm = j;
			}
		}
	}
}

void print_sol_rec(FILE* fout, int im, int jm)
{
	if(lsc[im][jm] <= 0 || im<=0 || jm<=0 )
		return;

	if(A[im] == B[jm]) {
		print_sol_rec(fout, --im, --jm);
		fprintf(fout, "%d ", A[++im]);
		return;
	}

	if (lsc[im][jm] == lsc[im-1][jm]) return print_sol_rec(fout, --im, jm);
	else return print_sol_rec(fout, im, --jm);
}
int main()
{
	FILE *f, *fout;
	int i;

	f = fopen("cmlsc.in", "r");

	fscanf(f, "%d %d", &M, &N);
	for(i  = 1 ; i <= M; i++ ) {
		fscanf(f, "%d", &A[i]);
	}
	for(i  = 1 ; i <= N; i++ ) {
		fscanf(f, "%d", &B[i]);
	}
	fclose(f);

	solutie_cmlsc();

	fout = fopen("cmlsc.out", "w");
	fprintf(fout, "%d\n", smax);
	print_sol_rec(fout, im, jm);
	fprintf(fout, "\n");

	fclose(fout);
	return 0;
}
