#include<stdio.h>
int main()
{
	int a,b,aux,r,t,i;
	FILE*f=fopen("euclid2.in","r");
	FILE*g=fopen("euclid2.out","w");
	fscanf(f,"%d",&t);
	for(i=1;i<=t;i++)
	{
	fscanf(f,"%d %d",&a,&b);
	if(a<b)
	{
		aux=a;
		a=b;
		b=aux;
	}
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	
		fprintf(g,"%d\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;

}