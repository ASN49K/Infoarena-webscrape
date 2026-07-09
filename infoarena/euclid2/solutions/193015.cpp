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
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

while()
{
scanf("%ld%ld",&a,&b)
printf("%ld\n",c(a,b));
}
return 0;
}
