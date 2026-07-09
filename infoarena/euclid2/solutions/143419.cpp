#include <stdio.h>

int a,b,r;

int main()
{
	freopen("cmmdc.in","r",stdin);
	freopen("cmmdc.out","w",stdout);
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