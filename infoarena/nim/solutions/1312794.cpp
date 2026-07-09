#include <stdio.h>
#define NMAX 10023
FILE *fin, *fout;
int t, n, sum, temp;
int main()
{
	fin = fopen("nim.in", "r");
	fout = fopen("nim.out", "w");
	fscanf(fin, "%d", &t);
	for(int i = 0; i< t; i++)
	{
		fscanf(fin, "%d", &n);
		sum = 0;
		for(int i = 0; i< n; i++)
		{
			fscanf(fin, "%d", &temp);
			sum = sum xor temp;
		}
		if(sum == 0) fprintf(fout, "NU\n");
		else fprintf(fout, "DA\n");
	}	
	fclose(fin);
	fclose(fout);
	return 0;
}
