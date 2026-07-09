#include <stdio.h>

int cmmdc(int x, int y)
{
	if(x < y)
	{
		int aux = x; x = y; y = aux;
	}
	
	int q = x % y;
	while (q != 0)
	{
		fflush(stdout);
		x = y;
		y = q;
		q = x % y;
	}
	return y;
}

int main()
{
	int T, a, b;
	FILE *inFile = fopen("euclid2.in", "r");
	FILE *outFile = fopen("euclid2.out", "w");
	
	fscanf(inFile, "%d", &T);
	
	for(int i = 0; i < T; i++)
	{
		fscanf(inFile, "%d %d", &a, &b);
		fprintf(outFile, "%d\n", cmmdc(a, b));
	}
	
	return 0;
}
