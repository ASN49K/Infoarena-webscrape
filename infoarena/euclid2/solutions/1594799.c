#include <stdio.h>

int T, A, B;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int main(void)
{
	FILE*fin = fopen("euclid2.in", "r");
	FILE*fout = fopen("euclid2.out", "w");

	fscanf(fin, "%d", &T);
	for (; T; --T)
	{
		fscanf(fin, "%d %d", &A, &B);
		fprintf(fout, "%d\n", gcd(A, B));
	}

	return 0;
}