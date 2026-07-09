#include<stdio.h>
#define FOR(i,t) for(i=1;i<=t;i++)
long t;


void read()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
long r,i,a,b;
scanf("%ld",&t);
FOR(i,t)
	{
	scanf("%ld%ld",&a,&b);
	while(b)
		{
		r=a%b;
		a=b;
		b=r;
		}
	printf("%ld\n",a);
	}
}


int main()
{
read();
return 0;
}