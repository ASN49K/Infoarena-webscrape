#include <stdio.h>

#define FOR(p,n) for(int i=p;i<n;i++)

long cmmdc(long a, long b)
{
	long c;
	while (b)
	{
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	long a,b;
	int T;
	FILE *f= fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
	fscanf(f,"%d",&T);
	FOR(0,T)
	{
		fscanf(f,"%ld %ld",&a,&b);
		fprintf(g,"%ld\n",cmmdc(a,b));
	}
	return 0;
}