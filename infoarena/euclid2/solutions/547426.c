#include <stdio.h>

unsigned long cmmdc(unsigned long, unsigned long);

int main(argc, argv)
int argc;
char *argv[];
{
	int T;
	unsigned long a, b; 
	int i;
	FILE *fin = fopen("euclid2.in", "r");
	FILE *fout = fopen("euclid2.out", "w");
	fscanf(fin, "%d", &T);
	for (i=0; i<T; ++i) {
		fscanf(fin, "%ld %ld", &a, &b);
		fprintf(fout, "%ld\n", cmmdc(a, b));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

unsigned long cmmdc(unsigned long a, unsigned long b)
{
	int r;
	while (b) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
