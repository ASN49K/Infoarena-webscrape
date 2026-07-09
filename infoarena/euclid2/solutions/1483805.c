#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int impartire(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int scadere(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void main()
{
	int n, a,b;
	FILE *p;
	FILE *q;
	p = fopen("algeuclidin.txt", "r");
	q = fopen("algeuclidout.txt", "w");
	fscanf(p,"%d",&n);
	int i;
	for (i = 1; i <= n; i++)
	{
		fscanf(p, "%d %d", &a, &b);
		fprintf(q,"%d", impartire(a, b));
		fprintf(q, "\n");

	}
}