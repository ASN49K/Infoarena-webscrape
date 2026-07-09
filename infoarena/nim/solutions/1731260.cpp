#include<stdio.h>

int bitXor(int x, int y)
{
	int a = x & y;
	int b = ~x & ~y;
	int z = ~a & ~b;
	return z;
}

int main()
{
	FILE *inputFile, *outputFile;
	inputFile=fopen("nim.in", "r");
	outputFile=fopen("nim.out", "w");

	int t, i,j, n, x, y, z, xor;
	fscanf(inputFile, "%d", &t);
	for(i=1; i<=t; i++)
	{
		fscanf(inputFile, "%d", &n);
		fscanf(inputFile, "%d", &x);
		fscanf(inputFile, "%d", &y);
		xor=bitXor(x,y);
		for(j=3; j<=n; j++)
		{
			fscanf(inputFile, "%d", &z);
			xor=bitXor(xor,z);
		}
		//printf("%d",xor);
		if(xor == 0)
		{
			fprintf(outputFile, "NU\n");
		}
		else
		{
			fprintf(outputFile, "DA\n");
		}
	}

	
	return 0;
}
