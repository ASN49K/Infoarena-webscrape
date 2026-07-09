#include<stdio.h>
FILE *in=fopen("euclid2.in","r");
FILE *out=fopen("euclid2.out","w");
long int n,i,a,b,r;
int main()
{
	fscanf(out,"%ld",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(out,"%ld",&a);
		fscanf(out,"%ld",&b);
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fprintf(out,"%ld\n",a);
	}
	return 0;
}
