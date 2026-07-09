#include <stdio.h>

FILE *fin = fopen("euclid2.in", "r");
FILE *fout = fopen"euclid2.out", "w");

int euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return euclid(b, a%b);
}

int main()
{
	int n,a,b;
	fscanf(fin, "%d", &n);
	while (n > 0)
	{
		fscanf(fin, "%d%d", &a, &b);
		fprintf(fout, "%d\n", euclid(a, b));
	}
}