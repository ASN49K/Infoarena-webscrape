#include <cstdio>
using namespace std;
int n,i,a,b;
int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
