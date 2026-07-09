#include<stdio.h>

long cmmdc(long a,long b)
{
	while(a!=b)
		if(a>b)
			a-=b;
		else
			b-=a;
	return a;
}
int main()
{
	long t,a,b,c;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%ld%ld",&a,&b);
		c=cmmdc(a,b);
		printf("%ld",c);
	}
	return 0;
}
		