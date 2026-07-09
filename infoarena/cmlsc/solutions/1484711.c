#include <stdio.h>
#define MAX 1024

int main() {
	FILE* fin = fopen("cmlsc.in", "r");
	int n, m;
	fscanf(fin, "%d %d\n", &m, &n);
	int i, j;
	int a[MAX], b[MAX];
	for(i=0; i<m; i++) {
		fscanf(fin, "%d ", &a[i]);
	}
	fscanf(fin, "\n");
	for(j=0; j<n; j++) {
		fscanf(fin, "%d ", &b[j]);
	}
	fclose(fin);
	
	int c[MAX][MAX];
	//memset(c, 0, sizeof(c));
	if(a[0] == b[0]) {
		c[0][0] = 1;
	} else {
		c[0][0] = 0;
	}
	for(i=1; i<m; i++) {
		if(a[i] == b[0]) {
			c[i][0] = 1;
		} else {
			c[i][0] = c[i-1][0];
		}
	}
	for(j=1; j<n; j++) {
		if(a[0] == b[j]) {
			c[0][j] = 1;
		} else {
			c[0][j] = c[0][j-1];
		}
	}
	for(i=1; i<m; i++) {
		for(j=1; j<n; j++) {
			if(a[i] == b[j]) {
				c[i][j] = c[i-1][j-1] + 1;
			} else {
				if(c[i-1][j] > c[i][j-1]) {
					c[i][j] = c[i-1][j];
				} else {
					c[i][j] = c[i][j-1];
				}
			}
		}
	}
	int res = c[m-1][n-1];
	int sir[MAX];
	int i = m - 1;
	int j = n - 1;
	int pos = res - 1;
	while((i > 0) || (j > 0)) {
		if(a[i] == b[j]) {
			sir[pos] = a[i];
			i--;
			j--;
			pos--;
		} else {
			if(i > 0 || c[i][j] == c[i - 1][j]) {
				i--;
			} else {
				j--;
			}
		}
	}
	
	FILE* fout = fopen("cmlsc.out", "w");
	fprintf(fout, "%d\n", res);
	for(i=0; i<res; i++) {
		fprintf(fout, "%d ", sir[i]);
	}
	fprintf(fout, "\n");
	fclose(fout);
	return 0;
}