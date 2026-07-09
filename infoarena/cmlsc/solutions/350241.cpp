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
	long a,b,c;
	int T;
	FILE *f= fopen("cmmdc.in","r"),*g=fopen("cmmdc.out","w");
	fscanf(f,"%ld %ld",&a,&b);
	c = cmmdc(a,b);
	fprintf(g,"%ld\n",(c==1 ? 0 : c));
	return 0;
}