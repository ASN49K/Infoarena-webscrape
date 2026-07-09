#include <stdio.h>

#define NMAX 1024
#define MAX(a,b) ((a > b) ? a : b)

int m, n, c[NMAX];

int cmlsc(int a[], int b[]) {
	int r[NMAX][NMAX];
	int i, j;
	
	for (i=1; i<=m; i++) {
		for (j=1; j<=n; j++) {
			if (a[i-1] == b[j-1])
				r[i][j] = r[i-1][j-1] + 1;
			else 
				r[i][j] = MAX(r[i-1][j], r[i][j-1]);
		}
	}
	
	int count = 0;
	for (i=m,j=n; i; ) {
		if (a[i-1] == b[j-1]) {
			c[count++] = a[i-1];
			i--; j--;
		} else {
			if (r[i-1][j] < r[i][j-1]) j--;
			else i--;
		}
	}
	return r[m][n];
}

int main(void) {
	FILE *f, *g;
	int a[NMAX], b[NMAX];
	int i, j, lung;
	
	f = fopen("cmlsc.in", "r");
	g = fopen("cmlsc.out", "w");
		
	fscanf(f, "%d %d\n", &m, &n);
	for (i=0; i<m; i++) {
		fscanf(f, "%d", &a[i]);
	}
	for (i=0; i<n; i++) {
		fscanf(f, "%d", &b[i]);
	}
	lung = cmlsc(a, b);
	
	// print solution
	fprintf(g, "%d\n", lung);
	for (i=lung-1; i>=0; i--) {
		fprintf(g, "%d ", c[i]);
	}
	
	fclose(f);
	fclose(g);
}