#include <stdio.h>


int cmmdc(int x, int y)
{
	int d = 0;

	while (y != 0)
	{
		d = y;
		y = x % y;
		x = d; 
	}

	return x;
}

int main()
{
	FILE *in = fopen("euclid2.in", "rt");
	
	int nrPairs = 0;
	fscanf(in, "%d", &nrPairs);

	FILE *out = fopen("euclid2.out", "wt");

	int i;

	for (i = 0; i < nrPairs; i++)
	{
		int a = 0, b = 0;
		fscanf(in, "%d %d", &a, &b);
		int rez = cmmdc(a, b);
		printf("%d\n", rez);
		fprintf(out, "%d\n", rez);
	}

	fclose(in);
	fclose(out);
	return 0;
}