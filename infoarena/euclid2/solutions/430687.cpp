#include<cstdio>
FILE *f=fopen("euclid2.in","r"), *g=fopen("euclid2.out","w");
long cmmdc(long x, long y)
{
	if(!y) return x;
	return cmmdc(y, x%y);
}
int main()
{
	long t,a,b;
	fscanf(f,"%ld",&t);
	for(;t;t--)
	{
		fscanf(f,"%ld %ld",&a,&b);
		fprintf(g,"%ld\n",cmmdc(a,b));
	}
	return 0;
}
