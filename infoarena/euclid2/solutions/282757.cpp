#include<stdio.h>
FILE *in=fopen("euclid2.in","r");
FILE *out=fopen("euclid2.out","w");
long int n,a,b,i,r;
void main()
{
fscanf(in,"%ld",&n);
for(i=1;i<=n;i++)
	{
	fscanf(in,"%ld",&a);
	fscanf(in,"%ld",&b);
	while(b!=0)
		{
		r=a%b;
		a=b;
		b=r;
		}
	fprintf(in,"%ld\n",a);
	}
}