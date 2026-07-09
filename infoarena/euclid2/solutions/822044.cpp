#include<cstdio>
using namespace std;
long long a,b,T;
int i,r;
int cmmdc(int x, int y)
{
	int z;
	while(y!=0)
	{
		z=y;
		y=x%y;
		x=z;
	}
	return x;

}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%lld",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%lld%lld",&a,&b);
		printf("%d",cmmdc(a,b));

	}
	return 0;
}
