#include<stdio.h>

long cmmdc(long a,long b)
{
	if(b)
		return cmmdc(b,a%b);
	return a;
}

int main()
{
	FILE* f1,*f2;
	f1=fopen("euclid2.in","r");
	f2=fopen("euclid2.out","w");
	long a,b,T;
	fscanf(f1,"%ld",&T);
	for(int i=0;i<T;i++)
	{
		fscanf(f1,"%ld %ld",&a,&b);
		fprintf(f2,"%ld\n",cmmdc(a,b));
	}
	fcloseall();
	return 0;
}