#include <stdio.h>

int main() {
	FILE fin = fopen("nim.in", "r");
	int t, n;
	fscanf(fin, "%d\n", &t);
	int i, j;
	FILE* fout = fopen("nim.out", "w");
	
	for(i=0; i<t; i++) {
		fscanf(fin, "%d\n", &n);
		int sum = 0;
		int x;
		for(j=0; j<n; j++) {
			fscanf(fin, "%d ", &x);
			sum = sum ^ x;
		}
		fscanf(fin, "\n");
		if(sum > 0) {
			fprintf(fout, "DA\n");
		} else {
			fprintf(fout, "NU\n");
		}
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}