#include<cstdio>
main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,i,a,b,c;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		c=1;
		while (c)
		{
			if (a>b)
			{
				c=a%b;
				a=c;
			}
			else 
			{
				c=b%a;
				b=a;
				a=c;
			}
		}
		printf("%d\n",b);
	}
}
			