#include<cstdio>
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,i,c,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
		{
			while(b!=0)
			{
				c=a%b;
				a=b;
				b=c;
			}
			printf("%d\n",a);
		}
		else 
		{
			while(a!=0)
			{
				c=b%a;
				b=a;
				a=c;
			}
			printf("%d\n",b);
		}
		
	}
	return 0;
}
