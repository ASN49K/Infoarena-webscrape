#include <stdio.h>

int main()
{
	int x, y, r;
	fscanf(fopen("euclid2.in", "r"),"%d %d\n", &x, &y);
	while (y)
	{
		r=x%y;
		x=y;
		y=r;
	}
	fprintf(fopen("euclid2.out", "w"), "%d", x);
	return 0;
}