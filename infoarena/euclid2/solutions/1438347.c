#include<stdio.h>
#include<stdlib.h>
int euclid(int a, int b)
{
	if (!b)
		return a;
	return euclid(b, a % b);
}
int main()
{
	FILE *f, *g;
	int T, a, b;
	f = fopen("euclid2.in", "r");
	g = fopen("euclid2.out", "w");
	fscanf(f, "%d", &T);
	while (T)
	{
		fscanf(f, "%d %d", &a, &b);
		fprintf(f,"%d\n", euclid(a, b));
		T--;
	}
	return 0;
}