#include<stdio.h>

int cmmdc(int a, int b)
{
	if(!b)
		return a;
	else 
		return cmmdc(b, a%b);
	}
void main()
{
	int x, y, T, i;
	FILE *f,*g;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	fscanf(f,"%d",&T);
	for(i=0;i<T;i++)
	{
		fscanf(f,"%d%d",&x,&y);
		fprintf(g,"%d\n",cmmdc(x,y));
	}

}