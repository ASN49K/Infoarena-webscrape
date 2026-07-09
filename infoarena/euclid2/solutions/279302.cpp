#include<stdio.h>
long c;
FILE *f=fopen("euclid.in","r"),
	*g=fopen("euclid.out","w");
void citire()
{	
	fscanf(f,"%ld",&c);
}
long cmmdc(long a,long b)
{
	if(!b) return a;
	return cmmdc(b,a%b);
}
void write()
{
	long a,b,res;
	for(long i=1;i<=c;i++)
	{
		fscanf(f,"%ld %ld",&a,&b);
		res=cmmdc(a,b);
		fprintf(g,"%ld\n",res);
	}
}
int main(void)
{
	citire();write();
	return 0;
	fcloseall();
}