#include<stdio.h>
unsigned cmmdc(unsigned a, unsigned b)
{
	unsigned r;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
int main()
{
	unsigned i,n,a,b;
	FILE *f, *g;
	f=fopen ("euclid2.in","r");
	g=fopen ("euclid2.out","w");
	fscanf(f,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(f,"%d",&a);
		fscanf(f,"%d",&b);
		fprintf(g,"%d\n",cmmdc(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}