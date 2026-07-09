/* 
Problema de programare dinamica: cel mai lung subsir comun. 
Complexitate: O(m * n)   
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN		1024

#define max(x, y) ((x > y) ? x : y)
#define min(x, y) ((x < y) ? x : y)

int m, n;
int vector_1[LEN], vector_2[LEN];
int res[LEN][LEN];

void lcs_matrix () {
	int i, j;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) {
			if (vector_1[i] == vector_2[j])
				res[i][j] = res[i - 1][j - 1] + 1;
			else
				res[i][j] = max(res[i][j - 1], res[i - 1][j]);
		}	
}

void lcs_print () {
	FILE *f_out = fopen("cmlsc.out", "w");
	lcs_matrix();

	int lung_min = min(m, n);
	int subsir_comun[lung_min];

	int lung = 0;
	int i = m - 1;
	int j = n - 1;
	while (i > 0 || j > 0) {
		if (vector_1[i] == vector_2[j]) {
			subsir_comun[lung++] = vector_1[i];
			i--;
			j--;
		}
		else 
			if (res[i - 1][j] < res[i][j - 1])
				j--;
			else
				i--;
	}

	fprintf(f_out, "%d\n", lung);
	for (i = lung - 1; i >= 0; i--)
		fprintf(f_out, "%d ", subsir_comun[i]);
		
	fclose(f_out);
}

int main () {
	FILE *f_in = fopen("cmlsc.in", "r");

	fscanf(f_in, "%d %d", &m, &n);
	int i;
	for (i = 0; i < m; i++) {
		fscanf(f_in, "%d", &vector_1[i]);
	}
	for (i = 0; i < n; i++) {
		fscanf(f_in, "%d", &vector_2[i]);
	}
	
	lcs_print();

	fclose(f_in);
	return 0;
}
