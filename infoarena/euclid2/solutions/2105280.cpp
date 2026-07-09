#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f=fopen("euclid2.in", "r"),
		 *g=fopen("euclid2.out", "w");
    int x, n1, n2, r;
    fscanf(f, "%d", &x);
    for(int i=1;i<=x;i++)
	{
		fscanf(f, "%d %d", &n1, &n2);
		while(n2)
		{
			r=n1%n2;
			n1=n2;
			n2=r;
		}
		fprintf(g, "%d\n", n1);
	}
    return 0;
}
