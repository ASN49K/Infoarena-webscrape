#include <stdio.h>
int n, a, b;
FILE*fin=fopen("euclid2.in", "r");
FILE*fout=fopen("euclid2.out", "w");

int euclid(int a, int b)
{
	if (!b)	return a;
	return euclid(b, a%b);
}

int main()
{
	
	fscanf(fin, "%d", &n);
	while (n > 0)
	{
		fscanf(fin, "%d%d", &a, &b);
		fprintf(fout, "%d\n", euclid(a, b));
	}
	return 0;
}