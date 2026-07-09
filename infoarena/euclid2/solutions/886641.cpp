#include<stdio.h>
long cmmdc(long a, long b)
{   long r;
	while(b)
	{
		r=a%b;
		a=b;
	    b=r;
    }
	 return a;
}
long t,x,y;
int main()
{
	FILE *f;
	FILE *g;
	f=fopen("euclid2.in","rt");
	g=fopen("euclid2.out","wt");
	fscanf(f,"%d", &t);
	for(long i=1;i<=t;i++)
	{	
		fscanf(f,"%d %d", &x, &y);
		fprintf(g,"%d\n",cmmdc(x,y));
	}
	fclose(f);
	fclose(g);
	return 0;
}