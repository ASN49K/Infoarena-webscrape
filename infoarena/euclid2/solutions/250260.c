#include <stdio.h>
#include <stdlib.h>

long int cmmdc(long int a, long int b)
{
	long int temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	long int a,b,t, i;
	FILE *fin, *fout;
	
	if ((fin = fopen("euclid2.in", "r")) == NULL)
	{
		printf("Eroare \n");
		exit(-1);
	}
	fscanf(fin, "%ld", &t);
	fout = fopen("euclid2.out", "w");
	for (i = 0; i < t; i++)
	{
		fscanf(fin,"%ld%ld", &a, &b);
		if (a == b)
			fprintf(fout, "%ld\n", a);
		else if (a == 1)
			fprintf(fout, "%ld\n", b);
		else if (b == 1)
			fprintf(fout, "%ld\n", a);
		else
			fprintf(fout,"%ld\n", cmmdc(a,b));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
