#include<stdio.h>
int main()
{
	unsigned long a,b,t,r,i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld%ld",&a,&b);
		r=a%b;a=b;b=r;
		while(r)
		{
			r=a%b;a=b;b=r;
		}
		printf("%ld ",r);
	}
	return 0;
}