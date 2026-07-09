#include <stdio.h>

int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a %b);
}

int main()
{
	FILE *f,*g;
	int n,i;
	int a,b;
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");	
	fscanf(f,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",gcd(a,b));
	}
}