#include <stdio.h>
#include <stdlib.h>
int cmmdc(int x, int y)
{
	if (x == 0)
	{
		return y;
	}
	if (y == 0)
	{
		return x;
	}
	return cmmdc(y, x%y);
}
int main()
{
	FILE *f = fopen("euclid2.in", "r");
	FILE *g = fopen("euclid2.out", "w");
	int t, x, y;
	fscanf(f, "%d", &t);
	while (t--)
	{
		fscanf(f, "%d %d", &x, &y);
		fprintf(g, "%d\n", cmmdc(x, y));
	}
	fclose(f);
	fclose(g);
}