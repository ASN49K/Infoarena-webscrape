#include<stdio.h>
int t;
int euclid(int a,int b)
{
	int r;
	if(a<b)
	{
		r = a;
		a = b;
		b = r;
	}
	r = a%b;
	while(r)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}
int main()
{
	FILE*f = fopen("euclid2.in","r");
	FILE*g = fopen("euclid2.out","w");
	fscanf(f,"%d",&t);
	int a,b;
	while(t--)
	{
		fscanf(f,"%d %d ",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}