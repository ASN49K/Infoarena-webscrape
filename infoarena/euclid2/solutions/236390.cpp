#include <stdio.h>
FILE *f=fopen("euclid2.in","r"),
     *g=fopen("euclid2.out","w");

long cmmdc(long x, long y)
{
	if (x%y==0) return y;
	else cmmdc(y,x%y);
}

void scriere(long x)
{
	fprintf(g,"%ld\n",x);
}

void citire()
{
	long n,a,b,i;
	fscanf(f,"%ld",&n);
	for (i=1;i<=n;i++)
	{
		fscanf(f,"%ld %ld",&a,&b);
		scriere(cmmdc(a,b));
	}
}

int main()
{
	citire();
	fclose(f);
    fclose(g);
	return 1;
}
