#include<cstdio>

long gcd(long a,long b)
{
	if (!b) return a;
	else return gcd(b,a%b);
}

int main()
{
	FILE*f;
	FILE*g;
	long a,b,t;
	
	f = fopen("euclid2.in","r");
	g = fopen("euclid2.out","w");
	
	fscanf(f,"%li",&t);
	
	for (long i=0;i!=t;i++)
	{
		fscanf(f,"%li %li",&a,&b);
		fprintf(g,"%li\n",gcd(a,b));
	}
	
	return 0;
}
