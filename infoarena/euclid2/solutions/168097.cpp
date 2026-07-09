#include<stdio.h>
#define dim 101

int euc(int a,int b);

int n,a,b,i;

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	scanf("%d",&n);

	for(i=1; i<=n; ++i)
	{
		scanf("%d%d",&a,&b);

		printf("%d\n",euc(a,b));
	}
	return 0;
}
int euc(int a,int b)
{
	if(!b)

		return a;

	return euc(b,a%b);
}