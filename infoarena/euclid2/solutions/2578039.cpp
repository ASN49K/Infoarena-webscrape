#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	
	FILE *pfin = fopen("adunare.in", "r");
	FILE *pfout = fopen("adunare.out", "w");
	long int a, b;
	fscanf(pfin, "%ld%ld", &a, &b);
	fprintf(pfout, "%ld", a + b);
	fclose(pfin);
	fclose(pfout);
	
	return 0;
}