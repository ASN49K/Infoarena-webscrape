#include <stdio.h>
#include <stdlib.h>
int euclid(int a, int b)
{
	if(!b)
		return a;
	else euclid(b, a%b);
}
int main()
{
    FILE *f=fopen("euclid2.in", "r"),
		 *g=fopen("euclid2.out", "w");
    int x, n1, n2;
    fscanf(f, "%d", &x);
    for(int i=1;i<=x;i++)
	{
		fscanf(f, "%d %d", &n1, &n2);
		fprintf(g, "%d\n", euclid(n1, n2));
	}
    return 0;
}
