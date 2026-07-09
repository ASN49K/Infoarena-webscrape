#include <stdio.h>

int a, b, t;

int cmmdc (int a, int b)
{
	if (!b) return a;
	return cmmdc(b, a%b);
}

int main()
{
	FILE *g = fopen("euclid2.in", "r");
	FILE *f = fopen("euclid2.out", "w");
	fscanf(g, "%d", &t);
	
	for (; t; --t)
	{
		fscanf(g, "%d%d", &a, &b);
		fprintf(f, "%d\n", cmmdc(a, b));
	}
	
	return 0;
}
