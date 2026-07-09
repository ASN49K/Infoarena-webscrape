#include "stdio.h"

int main()
{
	FILE *f,*g;
	unsigned int n,a,b,u;
	f = fopen("euclid2.in","r");
	fscanf(f,"%d",&n);
	g = fopen("euclid2.out","w");
	while(n--)
	{
		fscanf(f,"%u%u",&a,&b);
		if(a>b)
		{		
			u = a;
			a = b;
			b = u;
		}
		while(a!=0)
		{
			u = b%a;
			b = a;
			a = u;
		}
		fprintf(g,"%u\n",b);
	}
	fclose(f);
	fclose(g);
	return 0;
}