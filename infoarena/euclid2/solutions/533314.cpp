#include<cstdio>

using namespace std;

long cmmdc(long a,long b)
{
	long r;
	r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
long t,a,b,i;


int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", cmmdc(a,b));
	}
return 0;
}