#include<stdio.h>

long euclid(long,long);

int main()
{
long n,a,b;
FILE *f=fopen("euclid.in","r");
FILE *g=fopen("euclid.out","w");
fscanf(f,"%lu",&n);
for(;n>0;n--)
	{
	fscanf(f,"%lu %lu",&a,&b);
	fprintf(g,"%lu\n",euclid(a,b));
	}
return 0;
}


long euclid(long a,long b)
{
	if (a>b) return euclid(b,a-b);
	if (a==b) return a;
	if (a<b) return euclid(a,b-a);
}