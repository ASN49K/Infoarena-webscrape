#include <cstdio>
#include <iostream>
using namespace std;
int a[10000],bune[10000];
int euclid(int a,int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main()
{	
	unsigned int i;
	FILE *intrare,*iesire;
	intrare=fopen("euclid2.in","r");
	fscanf(intrare,"%d",&T);
	for(i=1;i<=T;i++) fscanf(intrare,"%d %d",&a[2*i],&a[2*i+1]);
	fclose(intrare);
	for(i=1;i<=T;i++) 
	{
		bune[i]=euclid(a[2*i0,a[2*i+1]);
		
	}
	iesire=fopen("euclid.out","w");
	for(i=1;i<=T;i++) fprintf(iesire,"%d\n",bune[i]);
	fclose(iesire);
}
