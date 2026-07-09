#include <stdio.h>
long n,i,a,b,cmmdc;

int main()
	{
	freopen("euclid2","r",stdin);
	freopen("euclid2","w",stdout);
	scanf("%ld",&n);
	for(i=1; i<=n; ++i)
		{
		scanf("%ld%ld",&a,&b);
		do
			{
			cmmdc=a%b;
			a=b;
			b=cmmdc;
			}  while (cmmdc!=0);
		printf("%ld\n",a);
		}
	return 0;
	}


