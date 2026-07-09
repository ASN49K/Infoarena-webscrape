#include <cstdio>
using namespace std;

long cmmdc(long a,long b)
{
	long r=a%b;
	while (r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}	
	return b;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	long i,n,a,b;
	scanf("%ld",&n);
	for (i=0;i<n;i++)
	{
		scanf("%ld %ld",&a,&b);
		print("%ld\n";cmmdc(a,b));	
	}
	return 0;
}