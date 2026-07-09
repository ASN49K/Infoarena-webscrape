#include "stdio.h"

long int cmmdc(long int x,long int y)
{
	if(y==0)
		return(x);
	return cmmdc(y,x%y);
}

int main()
{
	FILE *f,*g;
	long int x,y,t,i;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");
	fscanf(f,"%ld",&t);
	for(i=0;i<t;i++)
	{
		fscanf(f,"%ld%ld",&x,&y);
		fprintf(g,"%ld\n",cmmdc(x,y));
	}
	fclose(f);
	fclose(g);
	return(0);
}
