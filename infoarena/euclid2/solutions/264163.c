#include<stdio.h>
int cmmdc(long a, long b)
{
	if(!b)
		return a;
	else
		return cmmdc(b, a%b);
}
int main()
{
	long a,b,c,t,i;
	FILE * f;
	FILE * g;
	f=fopen("euclid2.in", "r");
	g=fopen("euclid2.out", "w");
	fscanf(f,"%ld", &t);
	for(i=1;i<=t;i++)
	{
		fscanf(f,"%ld %ld", &a, &b);
		c=cmmdc(a,b);
		fprintf(g,"%ld\n", c);
	}
	fclose(f);
	fclose(g);
	return 0;
}