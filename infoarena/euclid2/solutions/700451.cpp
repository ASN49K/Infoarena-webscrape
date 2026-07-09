#include<stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int t,a,b;
int euclid2(int a,int b)
{
	while(a!=b)
	{
		if(a>b) a=a-b;
		else b=b-a;
	}
	fprintf(g,"%d\n",a);
}
int main()
{
	int i=0;
	fscanf(f,"%d",&t);
	while(i!=t)
	{
		fscanf(f,"%d%d",&a,&b);
		euclid2(a,b);
		i++;
	}
	fclose(f);
	fclose(g);
	return 0;
}
