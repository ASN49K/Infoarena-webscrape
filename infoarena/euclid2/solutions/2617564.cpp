#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int cmmdc(int a, int b)
{
	if (!b)
		return a;
	return cmmdc(b, a %b);
}

int main()
{
	FILE* fin = fopen("euclid2.in","r");
	if (fin == NULL)
		exit(0);
	FILE* fout = fopen("euclid2.out", "w");
	if (fout == NULL)
		exit(0);

	int n, x, y;
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fin, "%d%d", &x, &y);
		fprintf(fout, "%d\n", cmmdc(x, y));
	}
}