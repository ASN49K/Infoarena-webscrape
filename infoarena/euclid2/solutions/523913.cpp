#include<stdio.h>
long long t,i,a,b,r;
int main()
{
 freopen("euclid2.in","rt",stdin);
 freopen("euclid2.out","wt",stdout);
 scanf("%lld",&t);
 for(i=1;i<=t;i++)
	{
	 scanf("%lld%lld",&a,&b);
	 while(b) { r=a%b;a=b;b=r; }
	 printf("%lld\n",a);
	}
 return 0;
}