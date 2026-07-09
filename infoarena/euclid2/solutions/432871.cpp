#include <stdio.h>

long t,T,x,y;

long euclid(long x,long y)
{
	long r;
	do{
		r=x%y;
		x=y;
		y=r;
	}while(y);
	return x;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%ld%ld",&x,&y);
		printf("%ld\n",euclid(x,y));
	}
	return 0;
}
