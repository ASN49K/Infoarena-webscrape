#include <stdio.h>

int euclid(int a, int b)
{
	while (a != b)
	{
		if (a >= b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}

	return a;
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