#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE * f = fopen("nim.in", "r");
	int k,n;
	fscanf(f, "%i", &k);
	FILE * g = fopen("nim.out", "w");

	int i;
	for (i = 0; i < k; i++)
	{
		fscanf(f, "%i", &n);
		int j,sum = 0,x;
		for (j = 0; j < n; j++)
		{
			fscanf(f, "%i", &x);
			sum ^= x;
		}
		if (sum != 0)
		{
			fprintf(g, "%s\n", "DA");
		}
		else	
		{
			fprintf(g, "%s\n", "NU");
		}
	}
	fclose(f);
	fclose(g);
	
	return 0;
}

