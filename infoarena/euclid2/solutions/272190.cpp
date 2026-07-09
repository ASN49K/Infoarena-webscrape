#include <stdio.h>

int a, b, r, T;

int main()
{
	FILE *fin = fopen("euclid2.in", "rt"), *fout = fopen("euclid2.out", "wt");
	fscanf(fin, "%d", &T);
	while (T)
	{
		fscanf(fin, "%d %d", &a, &b);
		while (b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		fprintf(fout, "%d\n", a);
		T--;
	}
	fclose(fin), fclose(fout);
}
