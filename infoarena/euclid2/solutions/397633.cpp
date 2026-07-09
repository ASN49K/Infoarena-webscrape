#include<stdio.h>
long n,b,a,r,i;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%ld%ld", &a, &b);
		r=a%b;
		while(r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		printf("%ld\n", b);
	}
	return 0;
}