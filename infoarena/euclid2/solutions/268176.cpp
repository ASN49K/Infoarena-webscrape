#include<stdio.h>
FILE *in=fopen("euclid2.in","r");
FILE *out=fopen("euclid2.out","w");
int main()
{
 long int a,b,t,r,i;
 fscanf(in,"%ld",&t);
 for(i=1;i<=t;i++)
 {
		fscanf(in,"%ld",&a);
		fscanf(in,"%ld",&b);
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