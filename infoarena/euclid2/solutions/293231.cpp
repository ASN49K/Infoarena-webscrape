#include<stdio.h>

long i, t, a, b;
FILE *fin, *fout;

long cmmdc(long x, long y)
{
	long r = 1;

	while(y)
	{
		r = x % y;
		x = y;
		y = r;
	}

	return x;
}

int main()
{
	fin = fopen("euclid2.in", "rt");
	fout = fopen("euclid2.out", "wt");

	fscanf(fin, "%ld", &t);

	for(i = 1; i <= t; i++)
	{
		fscanf(fin, "%ld%ld", &a, &b);

		fprintf(fout, "%ld", cmmdc(a, b));
	}

	return 0;
}
