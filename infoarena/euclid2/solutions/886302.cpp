#include <stdio.h>

int lnko(int a, int b)
{
	if(!b) return a;
	else return lnko(b, a % b);
}

int main()
{
	int t, a, b;

	FILE * f;
	FILE * g;
	g = fopen("euclid2.out", "w");
	f = fopen("euclid2.in", "r");

	fscanf(f, "%d", &t);
	for(int i=1; i<t; i++)
	{
		fscanf(f, "%d %d", &a, &b);
		fprintf(g, "%d\n", lnko(a, b));
	}
}