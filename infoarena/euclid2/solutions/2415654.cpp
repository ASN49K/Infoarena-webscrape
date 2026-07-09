#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b; b = r;
	}
	return a;
}
int main()
{
	int nr;
	int a, b;
	FILE* fp = fopen("euclid.in", "r");
	FILE* fout=fopen("euclid.out", "w");
	fscanf(fp,"%d", &nr);
	for (int i = 0; i < nr; i++)
	{
		fscanf(fp,"%d %d", &a, &b);
		fprintf(fout, "%d\n", cmmdc(a, b));
	}
	fclose(fp);
	fclose(fout);
	return 0;
}