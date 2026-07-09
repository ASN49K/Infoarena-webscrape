#include<stdio.h>
long int cmmdc(long int a,long int b)
{
	if(!b) return a; return cmmdc(b,a%b);
}
int main(void)
{
	long int c;
	FILE *f=fopen("euclid.in","r"),*g=fopen("euclid.out","w");
	fscanf(f,"%ld",&c);
	long int a,b,res;
	for(long int i=1;i<=c;i++)
	{
		fscanf(f,"%ld %ld",&a,&b);
		res=cmmdc(a,b);
		fprintf(g,"%ld\n",res);
	}
	return 0;
	fcloseall();
}