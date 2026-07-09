#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int cmmdc(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void euclid1()
{
	FILE* fp1, * fp2;
	fp1 = fopen("euclid2.in", "r");
	fp2 = fopen("euclid2.out", "w");
	int T;
	fscanf(fp1, "%d", &T);
	for (int i = 0; i < T; i++)
	{
		int a, b;
		fscanf(fp1, "%d%d", &a, &b);
		fprintf(fp2, "%d\n", cmmdc(a, b));
	}
	fclose(fp1);
	fclose(fp2);
}
void main()
{
	euclid1();

}
