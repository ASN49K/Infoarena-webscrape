#include <stdio.h>
#include <stdlib.h>

#define IN_FILE "cmlsc.in"
#define OUT_FILE "cmlsc.out"
#define max(a, b) ((a) > (b) ? (a) : (b))


int gcd (int a , int b) {
	if (b != 0) {
		return gcd(b, a % b);
	}
	return a;
}
  
int main() 
{
	int n = 0, m = 0, i = 0, j = 0;
	int *a;
	int *b;
	int **d;

	FILE * in_file = fopen(IN_FILE, "r");
	FILE * out_file = fopen(OUT_FILE, "w");

	fscanf(in_file, "%d", &n);
	fscanf(in_file, "%d", &m);

	a = (int*)malloc(n * sizeof(int));
	b = (int*)malloc(m * sizeof(int));
	d = (int**)malloc((n+1) * sizeof(int*));
	for (i = 0; i <= n ; i ++) {
		d[i] = (int*)calloc((m + 1) , sizeof(int));
	}

	for (i = 0; i < n ; i ++) {
		fscanf(in_file, "%d", &a[i + 1]);
	}

	for (i = 0; i < m ; i ++) {
		fscanf(in_file, "%d", &b[i + 1]);
	}

	for (i = 1 ; i <= n ; i ++) {
		for (j = 1; j <= m; j++ ) {
			if (a[i] == b[j]) {
				d[i][j] = d[i-1][j-1] + 1;
			} else {
				d[i][j] = max(d[i-1][j],d[i][j-1]);
			}
		}
	}
	// print sequence size
	fprintf(out_file, "%d\n", d[n][m]);
	// backtrack sequence
	i = 1;
	j = 1;
	while (i <= n && j <= m) {
		if (a[i] == b[j] && d[i][j] == d[i-1][j-1] + 1) {
			fprintf(out_file, "%d ", a[i]);
			i++;
			j++;
		} else if (i < n) {
			i++;
		} else {
			j++;
		}
	}
	//fprintf(out_file, "%d\n", gcd(a, b));
	fclose(in_file);
	fclose(out_file);
	return 0;
}
