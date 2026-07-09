#include<stdio.h>
long c(long a, long b)
	{
	if(!b)
		return a;
	else
	       return 	c(b,(a%b));
	}

int main()

{
long a,b;
freopen("cmmdc.in","rt",stdin);
freopen("cmmdc.out","wt",stdout);

while(scanf("%ld%ld",&a,&b))
{
printf("%ld\n",c(a,b));
}
return 0;
}
