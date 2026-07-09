#include<fstream>
using namespace std;
FILE *f, *g;
long long x, y, i, n;
long long euclid(long long a, long long b)
{
	long long rest;
	while(b>0)
	{
		rest=a%b;
		a=b;
		b=rest;
	}
	return a;
}
int main()
{
	f=fopen("euclid2.in", "r");
	g=fopen("euclid2.out","w");
	fscanf(f, "%lld", &n);
	for(i=1; i<=n; i++)
	{
		fscanf(f, "%lld %lld", &x, &y);
		fprintf(g, "%lld\n", euclid(x, y));
	}
	
	return 0;
} 
