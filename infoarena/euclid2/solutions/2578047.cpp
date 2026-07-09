#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int cmmdc(long int a, long int b)
{
	if (!b)
		return a;
	return cmmdc(b, a%b);
}

int main()
{
	int t;
	long int a, b;
	int i;
	FILE *pin = fopen("euclid2.in", "r");
	FILE *pout = fopen("euclid2.out", "w");
	fscanf(pin, "%d", &t);
	for (i = 0; i < t; i++)
	{
		
		fscanf(pin, "%ld %ld", &a, &b);
		if(i!=t-1)
		fprintf(pout, "%ld\n", cmmdc(a, b));
		else
			fprintf(pout, "%ld", cmmdc(a, b));
	}
	fclose(pin);
	fclose(pout);
	return 0;
}