#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,nr,i=0,rest,aux;
	FILE *f,*g;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	fscanf(f,"%i",&nr);
	while(i!=nr)
	{
		fscanf(f,"%i %i",&a,&b);
		while(a!=0 && b!=0)
		{
		aux=a/b;
		rest=a-aux*b;
		a=b;
		b=rest;
		}
	fprintf(g,"%i\n",a);
	i++;
	}
	return 0;
}