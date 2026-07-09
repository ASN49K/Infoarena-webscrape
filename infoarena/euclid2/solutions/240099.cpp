#include <stdio.h>

int main()
{
	int a, b, n, aux;
	FILE *fin = fopen("euclid2.in", "r");
	FILE *fout = fopen("euclid2.out", "w");

	fscanf(fin, "%d\n", &n);
	while(n)
	{
		fscanf(fin, "%d %d\n", &a, &b);

		if(a > b)
		{
			aux = a;
			a = b;
			b = aux;
		}
		while(a)
		{
			b = b % a;
			aux = a;
			a = b;
			b = aux;
		}
		fprintf(fout, "%d\n", b);
		n--;
	}
	fcloseall();
	return 0;
}