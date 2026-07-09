#include<stdio.h>
int T,a,b;

int euclid(int a, int b)
{
	if(b) 
		return euclid(b,a%b);
	return a;
}

int main()
{
	FILE*f=fopen("euclid2.in","r");
	FILE*g=fopen("euclid2.out","w");
	fscanf(f,"%d",&T);
	for(;T>0;--T)
	{
		fscanf(f,"%d%d",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}