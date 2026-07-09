#include <stdio.h>
int cmmdc(int a, int b)
{
	while(1) {
		if (a == b || a == 0)
			return b;
		if (b == 0)
			return a;
		if (a < b) {
			int temp;
			temp = a;
			a = b;
			b = temp;
		}
		a = a % b;
	}
}

int main()
{
	FILE *fin = fopen("euclid2.in", "r");
	FILE *fout = fopen("euclid2.out", "w");
	int pair_count,a,b,i;
	fscanf(fin, "%d", &pair_count);
	for (i = 0; i < pair_count ; i++) {
		fscanf(fin, "%d %d", &a, &b);
		fprintf(fout, "%d\n", cmmdc(a,b));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
