#include <stdio.h>

int cmmdc(int a, int b)
{
	int r;
	while (b)
	{
		r = a%b;
		a = b; 
		b = r;
	}
	return a;
}

int main()
{
	FILE *fin = fopen("euclid2.in", "r");
	FILE *fout = fopen("euclid2.out", "w");
	int i, a, b, n;

	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d %d", &a, &b);
		fprintf(fout, "%d\n", cmmdc(a, b));	
	}
	return 0;
}