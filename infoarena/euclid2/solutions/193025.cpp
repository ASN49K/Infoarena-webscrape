#include<stdio.h>
long c(long a, long b)
	{
	if(b==0)
		return a;
	else
	       return 	c(b,a%b);
	}

int main()

{
long a,b,t=0;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

for(;t;--t)
scanf("%ld%ld",&a,&b)
printf("%ld\n",c(a,b));
}
return 0;
}
