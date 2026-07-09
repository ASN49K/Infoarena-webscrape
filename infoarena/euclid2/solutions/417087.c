#include<stdio.h>
int a,b,r;
FILE *in,*out;
int main()
{
	in=fopen("euclid2.in","rt");
	out=fopen("euclid2.out","wt");
	fscanf(in,"%d %d",&a,&b);
	while (b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	fprintf(out,"%d",a);
	return 0;
}
