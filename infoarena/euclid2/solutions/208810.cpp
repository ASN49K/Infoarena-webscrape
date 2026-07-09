#include<stdio.h>

long euclid(long,long);

int main()
{
long n,a,b;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
fscanf(f,"%lu",&n);
for(;n>0;n--)
	{
	fscanf(f,"%ld %ld",&a,&b);
	fprintf(g,"%ld\n",euclid(a,b));
	}
return 0;
}


long euclid(long a,long b)
{
	if (b==0) return a;
	else return euclid(b,a%b);
}