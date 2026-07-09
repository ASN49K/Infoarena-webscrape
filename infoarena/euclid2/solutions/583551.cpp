#include<cstdio>
long cmmdc(long a,long b)
{
	long r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main()
{
	long a,b;
	int t,i;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d",&t);
for(i=1;i<=t;i++)
{
	scanf("%ld%ld",&a,&b);
	a=cmmdc(a,b);
	printf("%ld\n",a);
}
return 0;
}
