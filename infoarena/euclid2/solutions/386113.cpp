#include <stdio.h>

int cmmdc(int x, int y)
{
	if (!x)	return y;
	if (!y) return x;

	if (x > y)
		return cmmdc(x%y, y);
	else
		return cmmdc(x, y%x);
}

int main()
{
	int n, a, b;

	FILE *out = fopen("euclid2.out", "w");
	FILE *in = fopen("euclid2.in", "r");
		fscanf(in, "%d", &n);
		for (int i=0; i<n; i++)
		{
			fscanf(in, "%d%d", &a, &b);
			fprintf(out, "%d\n", cmmdc(a, b));
		}
	fclose(out);
	fclose(in);
}
