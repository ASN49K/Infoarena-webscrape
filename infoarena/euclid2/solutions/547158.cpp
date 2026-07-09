#include<cstdio>

long GCD(long a, long b)
{
   if (!b) return a;
   return GCD(b,a%b);
}
int main()
{int n,x,y;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
		scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		printf("%d \n",GCD(x,y));
	}
}
