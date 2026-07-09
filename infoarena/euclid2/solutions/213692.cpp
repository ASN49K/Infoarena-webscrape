#include<stdio.h>

int t, a, b, r;

int main()

{
	
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&t);
	while (t!=0)
	{
		t=t-1;
		scanf("%d%d",&a,&b);
		while (b!=0)
		{	r = a % b;
			a = b;
			b = r;
		}
		printf("%d\n",a);
	}
	return 0;
}
