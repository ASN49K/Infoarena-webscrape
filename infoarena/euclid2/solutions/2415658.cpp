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
	FILE* fp = fopen("euclid2.in", "r");
	FILE* fout=fopen("euclid2.out", "w");
	if (fscanf(fp, "%d", &nr) !=0)
	{
		for (int i = 0; i < nr; i++)
		{
			if (fscanf(fp, "%d %d", &a, &b) != 0)
				fprintf(fout, "%d\n", cmmdc(a, b));
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}