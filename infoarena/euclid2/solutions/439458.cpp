#include<stdio.h>
long long t,a,b,i;
int cmmdc(long long a,long long b)
{
	while(a!=b)
	{
		if(a>b)
		{
			a=a%b;
			if(a==0)
				a=b;
		}
		else
		{
			b=b%a;
			if(b==0)
				b=a;
		}
	}
	return a;
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
}
