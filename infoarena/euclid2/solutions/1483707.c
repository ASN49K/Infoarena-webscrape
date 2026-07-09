#include<stdio.h>

int cmmdc(int a, int b) {
	int c = a % b;
	while(c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main() {
	FILE* fin = fopen("euclid2.in", "r");
	int a, b, c;
	int t;
	fscanf(fin, "%d\n", &t);
	FILE* fout = fopen("euclid2.out", "w");
	int i;
	for(i=0; i<t; i++) {
		fscanf(fin, "%d %d\n", &a, &b);
		c = cmmdc(a, b);
		fprintf(fout, "%d\n", c);
	}
	
	fclose(fin);	
	fclose(fout);
	return 0;
}