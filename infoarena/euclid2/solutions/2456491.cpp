#define _CRT_SECURE_NO_WARNINGS
#define ALEX_THE_DUDE
#define T_MAX 100000

#include <stdio.h>
using namespace std;

FILE *fin, *fout;
int T;
long a, b;
int cmmdc(long &a, long &b)
{
	int r;
	while (r = a % b)
	{
		a = b;
		b = r;
	}

	return b;
}

int main()
{
	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");

	fscanf(fin, "%d", &T);

	while (T--)
	{
		fscanf(fin, "%d %d", &a, &b);
		fprintf(fout, "%d\n", cmmdc(a, b));
	}

	return 0;
}	