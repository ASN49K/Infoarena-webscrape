#include<stdio.h>

int N;

long int cmmdc(long int a,long int b)
{
	long int r;
	while(b)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

void citire(void)
{
	long int a;
	long int b;
	FILE *f = fopen("euclid2.in","r");
	FILE *g = fopen("euclid2.out","w");
		
	fscanf(f,"%d ",&N);
	for(int i=1;i<=N;i++)
	{
		fscanf(f,"%ld %ld",&a,&b);
		fprintf(g,"%ld\n",cmmdc(a,b));
	}
	
	fclose(g);
	fclose(f);
}

int main()
{
	citire();
	return 0;
}