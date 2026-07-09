#include<stdio.h>
FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");
int t,a,b;
int euclid(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main()
{
	fscanf(f,"%d",&t);
	for(int i=1;i<=t;++i)
	{
		fscanf(f,"%d%d",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
	}
	fclose(g);
	fclose(f);
	return 0;
}
