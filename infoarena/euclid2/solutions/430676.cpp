#include<stdio.h>

FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

int main(){

long a,b;
long n;
fscanf(f,"%ld",&n);
for(long i=0;i<n;i++)
{
	fscanf(f,"%ld",&a);
	fscanf(f,"%ld",&b);
	while(a!=0&&b!=0)
	{
		if(a>b)a=a%b;
		else b=b%a;
	}
	if(b==0)
	fprintf(g,"%ld\n",a);
	else fprintf(g,"%ld\n",b);
}
	fclose(f);
	fclose(g);
	return 0;
}