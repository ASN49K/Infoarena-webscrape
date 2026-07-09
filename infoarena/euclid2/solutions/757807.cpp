#include<stdio.h>

int cmmdc(int a, int b)
{
	int c;
	while(b)
	{
		c = b;
		b = a%b;
		a = c;
	}
	return a;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a>b)
			printf("%d\n",cmmdc(a,b));
		else
			printf("%d\n",cmmdc(b,a));
	}
	return 0;
}
