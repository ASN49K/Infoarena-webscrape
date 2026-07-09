#include <stdio.h>
FILE *f=fopen("euclid2.in","r"), *g=fopen("euclid2.out","w");
long euclid (long x, long y)
	{
	if (!y) return x;
	if (x>y) return euclid(y,x%y);
	else return euclid(x,y%x);
	}
int main()
{
long t,a,b,i;
fscanf(f,"%ld",&t);
for (i=1;i<=t;i++)
	{
	fscanf(f,"%ld %ld",&a,&b);
	fprintf(g,"%ld\n",euclid(a,b));
	}
return 0;
}