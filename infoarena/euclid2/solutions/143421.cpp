#include <stdio.h>

int a,b,r;

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&a);
	scanf("%d",&b);
	while (b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	if (b!=1) printf("%d",a);
	else printf("0");
	return 0;
}