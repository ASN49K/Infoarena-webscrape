#include <stdio.h>

int gcd(int a, int b)
{
	int tmp;
	while (b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	FILE *f, *g;
	int t, a, b, i;

	g = fopen("euclid2.out", "w");
	
	f = fopen("euclid2.in", "r");
	fscanf(f, "%d", &t);

	for (i = 0; i < t; i++)
	{
		fscanf(f, "%d", &a);
		fscanf(f, "%d", &b);
		fprintf(g, "%d\n", gcd(a, b));
	}

	fclose(f);
	fclose(g);
	
	return 0;
}
