#include <stdio.h>
long long int n, i, a, b, r;
int main(void)
{
freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%lld", &n);
for (i=1;i<=n;i++)
	{
	scanf("%lld%lld", &a, &b);
	r=a%b;
	while (r)
		{
   	a=b;
	   b=r;
  		r=a%b;
   	}
printf("%lld\n", b);
	}
fcloseall();
return 0;
}