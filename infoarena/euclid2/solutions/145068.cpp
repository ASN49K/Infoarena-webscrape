#include<stdio.h>

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	long long a,b,r=0;
	scanf("%lld%lld", &a, &b);
	while (r>1)
	{
		r=a%b;
		a=b;
		b=r;
	}
	printf("%lld", a);
	fclose(stdout);
	fclose(stdout);
	return 0;
}