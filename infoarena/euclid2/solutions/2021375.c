#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

typedef unsigned int uint;

uint gcd(uint a, uint b);

int main(void)
{
	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid2.out", "w");
	if(in != NULL && out != NULL)
	{
		uint n;
		fscanf(in, "%u%*c", &n);
		uint i = 0;
		for(; i < n; i++)
		{
			uint a, b;
			fscanf(in, "%u%*c%u%*c", &a, &b);
			fprintf(out, "%u\n", gcd(a, b));
		}

		fclose(in);
		fclose(out);
	}
	else
	{
		printf("Error\n");
	}

	return 0;
}

uint gcd(uint a, uint b)
{
	while(b)
	{
		uint temp = a;
		a = b;
		b = temp % a;
	}

	return a;
}