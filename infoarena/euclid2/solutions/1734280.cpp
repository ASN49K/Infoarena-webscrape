#include<stdio.h>

int cmmdc( int a, int b)
{
	int deimp=a;
	int imp=b;
	int rest;
	while(imp != 0)
	{
		rest=deimp%imp;
		deimp=imp;
		imp=rest;
	}
	return deimp;	
}

int main()
{
	FILE *inputFile=fopen("euclid2.in", "r"), *outputFile=fopen("euclid2.out","w");

	int n, x, y;
	fscanf(inputFile,"%d", &n);
	for(int i=1; i<=n; i++)
	{
		fscanf(inputFile,"%d %d", &x, &y);
		fprintf(outputFile, "%d\n", cmmdc(x,y));
	}

	return 0;
}