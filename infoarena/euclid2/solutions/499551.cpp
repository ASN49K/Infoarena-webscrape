#include<stdio.h>
FILE *in,*out;
int a,b,r,t;
int main()
{
	in=fopen("euclid2.in","rt");
	out=fopen("euclid2.out","wt");
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
