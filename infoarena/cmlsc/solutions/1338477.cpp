#include <stdio.h>

#define MAX(a, b) (a > b) ? (a) : (b)

short ** findLcs (int *u, int *v, int *lcs, int m, int n) {
	short **c = new short * [m + 1]();
	for (int i = 0; i < m+1; i++) {
		c[i] = new short[n + 1]();
	}
	
	int pos = 0;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (u[i] == v[j]) {
				c[i+1][j+1] = c[i][j] + 1;
				lcs[pos] = u[i];
				++pos;
			} else {
				c[i+1][j+1] = MAX(c[i][j+1], c[i+1][j]);
			}
		}
	}
	
	return c;
}
				

int main (void) {
	FILE *in = fopen("cmlsc.in", "r");
	FILE *out = fopen("cmlsc.out", "w");
	
	int m, n;
	fscanf(in, "%d %d", &m, &n);
	
	int *u = new int[m];
	int *v = new int[n];
	int *lcs = new int[MAX(m, n)];
	
	for (int i = 0; i < m; i++) {
		fscanf(in, "%d ", u+i);
	}
	
	for (int i = 0; i < n; i++) {
		fscanf(in, "%d ", v+i);
	}
	
	short **t = findLcs(u, v, lcs, m, n);
	
	fprintf(out, "%d\n", t[m][n]);
	for (int i = 0; i < t[m][n]; i++) {
		fprintf(out, "%d ", lcs[i]);
	}
	
	for (int i = 0; i < m+1; i++) {
		delete[] t[i];
	}
	delete[] t;
	delete[] u;
	delete[] v;
	delete[] lcs;
	fclose(in);
	fclose(out);
	
	return 0;
}
