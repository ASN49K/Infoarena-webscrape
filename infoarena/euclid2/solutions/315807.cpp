#include<stdio.h>
using namespace std;

int t;
long long a,b;

int cmmdc(long long a,long long b)
{
if(!b)return a;
return cmmdc(b,a%b);
}

int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&t);
for(int i=0;i<t;++i)
	{
	scanf("%lld %lld",&a,&b);
	printf("%d",cmmdc(a,b));
	}
return 0;
}


