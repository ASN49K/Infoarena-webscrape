#include "stdio.h"

unsigned int cmmdc(unsigned int a,unsigned int b)
{
	return (a==b?a:a<b?cmmdc(a,b%a):cmmdc(a%b,b));
}

int main()
{
	FILE *f,*g;
	unsigned int n,a,b;
	f = fopen("euclid2.in","r");
	fscanf(f,"%d",&n);
	g = fopen("euclid2.out","w");
	while(n--)
	{
		fscanf(f,"%u,%u",&a,&b);
		fprintf(g,"%u\n",cmmdc(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}