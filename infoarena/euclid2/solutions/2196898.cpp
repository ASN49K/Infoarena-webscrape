#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int euclid(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		if (a < b)
			b -= a;
	}
	if (a == b)
		return a;
}

void main()
{
	FILE* in = fopen("euclid2.in", "r");
	FILE* out = fopen("euclid2.out", "w");
	int i, n;
	int x, y;
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d %d", &x, &y);
		fprintf(out, "%d", euclid(x, y));
	}
	fclose(in);
	fclose(out);
}