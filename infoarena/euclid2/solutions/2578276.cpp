#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE* in = fopen("euclid2.in", "r");
	FILE* out = fopen("euclid2.out", "w");
	int a, b;
	int nr_per;
	fscanf(in, "%d", &nr_per);
	for (int i = 0; i < nr_per; i++)
	{
		fscanf(in, "%d", &a);
		fscanf(in, "%d", &b);
		/*while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}*/
		int c;
		while (b)
		{
			c = a % b;
			a = b;
			b = c;
		}
		fprintf(out, "%d\n", a);
	}
	return(0);
}