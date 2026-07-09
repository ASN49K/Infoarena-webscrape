#include<stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

long div(long a, long b)
{
	long r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
        r=a%b;
	}
	
	return b;
}

int main()
{
	long t,i,a,b;
	fscanf(f,"%ld",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(f,"%ld%ld",&a,&b);
		fprintf(g,"%ld\n",div(a,b));
	}
	
	fclose(f);
	fclose(g);
	return 0;
}