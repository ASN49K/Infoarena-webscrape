#include <stdio.h>
#include <stdlib.h>


#define INPUT		"cmlsc.in"
#define OUTPUT		"cmlsc.out"
#define MAXSIZE		1024
#define MAX(X, Y)	((X) > (Y) ? (X) : (Y))


void compute_lsc(int seq1[], int seq2[], int m, int n, int lsc[][MAXSIZE+1])
{
	int i, j;
	
	for (i = 0; i <= m; i++)
		lsc[0][i] = 0;

	for (i = 0; i <= n; i++)
		lsc[i][0] = 0;

	for (i = 1; i <=m; i++)
		for (j = 1; j <=n; j++)
			if (seq1[i-1] == seq2[j-1])
				lsc[i][j] = lsc[i-1][j-1] + 1;
			else
				lsc[i][j] = MAX(lsc[i-1][j], lsc[i][j-1]);
}

void travel(int lsc[][MAXSIZE+1], int seq1[], int seq2[], int i, int j, int *result, int pos)
{
	if (i == 0 || j == 0)
		return;

	if (seq1[i-1] == seq2[j-1])
		result[pos] = seq1[i-1], travel(lsc, seq1, seq2, i-1, j-1, result, pos-1);
	else
		if (lsc[i][j-1] > lsc[i-1][j])
			travel(lsc, seq1, seq2, i, j-1, result, pos);
		else
			travel(lsc, seq1, seq2, i-1, j, result, pos);	
}

int main(void)
{
	int m, n;
	int i;
	FILE *f_in, *f_out;
	int seq1[MAXSIZE], seq2[MAXSIZE];
	int lsc[MAXSIZE+1][MAXSIZE+1];
	int *result, len;
	
	f_in  = fopen(INPUT, "r");
	f_out = fopen(OUTPUT, "w");
	
	fscanf(f_in, "%d %d\n", &m, &n);
	
	for (i = 0; i < m - 1; i++)
		fscanf(f_in, "%d ", &seq1[i]);
	fscanf(f_in, "%d\n", &seq1[m-1]);
	
	for (i = 0; i < n - 1; i++)
		fscanf(f_in, "%d ", &seq2[i]);
	fscanf(f_in, "%d\n", &seq2[n-1]);
	
	compute_lsc(seq1, seq2, m, n, lsc);

	len = lsc[m][n];
	result = malloc(len * sizeof(int));
	travel(lsc, seq1, seq2, m, n, result, len-1);
	
	fprintf(f_out, "%d\n", len);
	for (i = 0; i < len - 1; i++)
		fprintf(f_out, "%d ", result[i]);
	fprintf(f_out, "%d\n", result[lsc[m][n]-1]);

	free(result);	
	fclose(f_in);
	fclose(f_out);
	
	return 0;
}
