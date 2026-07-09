#include <stdio.h>

void main(void)
{
	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid2.out", "w");
	int t, a, b, r;
	
	fscanf(in, "%d", &t);
	for(;t > 0; --t)
	{
		fscanf(in, "%d %d", &a, &b);
		while(b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		
		fprintf(out, "%d\n", a);
	}
	
	fclose(in);
	fclose(out);
}
