#include<stdio.h>

long gcd(long a,long b)
{
	if (b==0) 
		return a;
	return gcd(b,a%b);
}

int main()
{
	long n,a,b;
	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");
	fscanf(f,"%lu",&n);
	for(;n>0;n--)
	{
		fscanf(f,"%ld %ld",&a,&b);
		fprintf(g,"%ld\n",gcd(a,b));
	}
	return 0;
}

