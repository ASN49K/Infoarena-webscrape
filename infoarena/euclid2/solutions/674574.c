#include <stdio.h>
#include <stdlib.h>

long cmmdc(long a, long b)
{
    int r, aux;

    if(a==b) return a;
    if(a<b) {aux=a; a=b; b=aux;}

    r=a%b;

    while(r!=0)
    {
      r=a%b;
      a=b;
      b=r;
    }

    return b;
}

int main()
{
	FILE *fi, *fo;
	long a, b;
	int i, T;

	fi=fopen("euclid2.in", "r");
	fo=fopen("euclid2.out", "w");

	fscanf(fi, "%d", &T);
	for(i=1;i<=T;i++)
    {
        fscanf(fi, "%d %d", &a,&b);
        fprintf(fo, "%d\n", cmmdc(a, b));
    }

    fclose(fi);
    fclose(fo);

	return 0;
}
