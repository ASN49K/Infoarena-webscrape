#include <stdio.h>
#include <stdlib.h>

int tabel[1025][1025];

#define MAX(A, B) ((A) > (B) ? (A) : (B))

int cmlsc(int *a, int len_a, int *b, int len_b)
{
	int i,j;
	for( i = 0; i <= len_a; i++)
	for( j = 0; j <= len_b; j++)
		tabel[i][j] = 0;

	for(i = 1; i <= len_a; i++)
	for(j = 1; j <= len_b; j++){
		if (a[i-1] == b[j-1])
			tabel[i][j] = 1 + tabel[i-1][j-1];
		else {
			tabel[i][j] = MAX( tabel[i-1][j], tabel[i][j-1] ) ;
		}
	}

	return 0;
}

void reconstruct(FILE *fout, int *a, int len_a, int *b, int len_b)
{
	int i = len_a, j = len_b;
	while ( i > 0 && j > 0) {
		if( a[i-1] == b[j-1]) {
			fprintf(fout, "%d ", a[i-1]);
			i--; j--;
		}
		else {
			if (tabel[i-1][j] > tabel[i][j-1])
				i--;
			else
				j--;
		}
	}
	fprintf(fout, "\n");
}

int main()
{
	FILE *fin = fopen("cmlsc.in", "r");
	FILE *fout = fopen("cmlsc.out", "w");
	int a_len, b_len, i,j;
	fscanf(fin, "%d %d", &a_len, &b_len);
	int *a = malloc(a_len * sizeof(*a));
	int *b = malloc(b_len * sizeof(*a));

	for (i = 0; i < a_len ; i++) {
		fscanf(fin, "%d", &a[a_len-i-1]);
	}

	for (i = 0; i < b_len ; i++) {
		fscanf(fin, "%d", &b[b_len-i-1]);
	}

/*
	for ( i = 0; i< a_len; i++)
		printf("%d\t", a[i]);
	printf("\n");

	for ( i = 0; i< b_len; i++)
		printf("%d\t", b[i]);
	printf("\n");
*/
	cmlsc(a, a_len, b, b_len);

/*	for( i = 0; i <= a_len; i++,printf("\n"))
	for( j = 0; j <= b_len; j++) {
		printf("%d\t", tabel[i][j]);
	}
*/
	fprintf(fout, "%d\n" , tabel[a_len][b_len]);
	reconstruct(fout, a, a_len, b, b_len);
	free(a);
	free(b);
	fclose(fin);
	fclose(fout);
	return 0;
}
