#include <cstdio>

#define MaxN 100010

long long T,a,b;

long long cmmdc(long long x,long long y)
{
	if(!y)
		return x;
	else
		return cmmdc(y,x%y);
	
}

void rez()
{
	
	scanf("%lld",&T);
	long long i;
	for(i=0;i<T;i++)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",cmmdc(a,b));
	}
}
	

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	rez();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
