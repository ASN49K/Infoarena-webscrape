#include<stdio.h>
long t,i,a,b,c;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&t);
	for(i=1;i<=t;++i)
	{
		scanf("%ld%ld",&a,&b);
		while(b)
		{
			c=a%b;
			a=b;
			b=c;
		}
		printf("%ld\n",a);
	}
	return 0;
}