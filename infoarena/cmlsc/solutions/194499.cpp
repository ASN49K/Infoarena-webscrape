#include <stdio.h>

#define IN "euclid2.in"
#define OUT "euclid2.out"

int t,a,b;

int cmmdc(int a,int b)
{
	return (!b ? a : cmmdc(b,a%b));
}

void read()
{
	FILE *f=fopen(IN,"r");
	FILE *f2=fopen(OUT,"w");
	fscanf(f,"%d",&t);
	for (int i=0;i<t;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		fprintf(f2,"%d\n",cmmdc(a,b));
	}

	fclose(f);
	fclose(f2);
}


int main()
{
	read();
	
	return 0;
}