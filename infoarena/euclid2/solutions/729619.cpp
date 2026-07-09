#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
FILE *f1, *f2;
long unsigned t,a,b;
long unsigned cmmdc(long unsigned nr1,long unsigned nr2)
{
	if((nr1 + nr2) == 0) return 0;
	if((nr1*nr2) == 0) return nr1+nr2;
	while(nr1!=nr2)
	{
		if(nr1>nr2)nr1-=nr2;
		else nr2-=nr1;
	}
	return nr1;
}
int main()
{
	f1 = freopen("euclid2.in", "r", stdin);
	f2 = freopen("euclid2.out", "w", stdout);
	scanf("%lu", &t);
	for(;0<t;t--)
	{
		scanf("%lu %lu", &a,&b);
		printf("%lu\n", cmmdc(a,b));
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
