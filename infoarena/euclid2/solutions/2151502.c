#include <stdio.h>

int euclid(int a, int b)
{
	if (!b)
	{
		return a;
	}

	return euclid(b, a % b);
}

int main()
{
	FILE *in = fopen("euclid2.in","rt");
	FILE *out = fopen("euclid2.out","wt");

	int n, i;
	fscanf(in, "%d", &n);

	for (i = 0; i < n; i++)
	{
		int a, b;
		fscanf(in, "%d %d", &a, &b);
		fprintf(out, "%d\n", euclid(a, b));
	}

	fclose(in);
	fclose(out);
	return 0;
}