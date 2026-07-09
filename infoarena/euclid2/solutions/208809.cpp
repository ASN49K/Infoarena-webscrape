#include <stdio.h>

FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");

long a,b,t;

long euclid(long,long);

int main()
{
	fscanf(f,"%ld",&t);
	for(;t;--t)
		{
			fscanf(f,"%ld %ld",&a,&b);
			fprintf(g,"%ld\n",euclid(a,b));
		}
}
long euclid(long a,long b)
{
	if(b==0)
		return a;
	return euclid(b,a%b);
}