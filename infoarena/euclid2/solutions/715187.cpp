#include<cstdio>
using namespace std;

FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

long t,a,b;


void euclid (long x, long y)
{
	long r;
	
	while (y)
	 {
		 r=x%y;
		 x=y;
		 y=r;
	}
	
	fprintf(g,"%ld\n",x);
}


int main()
{
	
	fscanf(f,"%ld",&t);
	
	for (long i=1;i<=t;i++)
	{  fscanf(f,"%ld%ld",&a,&b);
		euclid (a,b);
	}
	
return 0;}