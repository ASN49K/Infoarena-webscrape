#include<stdio.h>
int cmmdc(long int a,long int b)
{
	if(!b) return a; return cmmdc(b,a%b);
}
int main(void)
{
	long int c,a,b,res;
	FILE *f=fopen("euclid.in","r"),*g=fopen("euclid.out","w");
	fscanf(f,"%ld",&c);
	for(long int i=1;i<=c;i++)
	{
		fscanf(f,"%ld %ld",&a,&b);
		res=cmmdc(a,b);
		fprintf(g,"%ld\n",res);
	}
	fcloseall();
	return 0;
}