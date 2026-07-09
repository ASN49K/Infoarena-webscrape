#include<stdio.h>
FILE *in,*out;
int a,b,r,t;
int main()
{
	in=fopen("euclid.in","rt");
	out=fopen("euclid.out","wt");
	fscanf(in,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		fscanf(in,"%d %d",&a,&b);
		while (b) 
		{
			r = a % b;
			a = b;
			b = r;
		}
		fprintf(out,"%d\n",a);
	}	
	
	return 0;
}
