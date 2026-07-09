#include <stdio.h>

int cmmdc(int a,int b)
{
	int r;
	while (b>0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	int n,a,b,i;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}

	return 0;
}