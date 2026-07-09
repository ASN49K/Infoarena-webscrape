#include <stdio.h>

int main()
{
	int a, b, n;
	FILE *fin = fopen("euclid2.in", "r");
	FILE *fout = fopen("euclid2.out", "w");

	fscanf(fin, "%d\n", &n);
	while(n)
	{
		fscanf(fin, "%d %d\n", &a, &b);

		while(a != b)
		{
			if(a < b)
				b = b % a;
			else
				a = a % b;
		}
		fprintf(fout, "%d\n", a);
		n--;
	}
	fcloseall();
	return 0;
}