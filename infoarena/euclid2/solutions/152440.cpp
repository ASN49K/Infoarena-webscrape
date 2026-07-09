#include<stdio.h>
long a,b,c;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%ld%ld",&a,&b);
	while(a&&b)
	{
		if (a>b)
			a%=b;
		else
			b%=a;

	}
	if (a)
		printf("%ld\n",a);
	else
		printf("%ld\n",b);

	return 0;
}