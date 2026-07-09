#include <stdio.h>

int a,b,T;
int cmmdc(int a, int b)
{	
	int r;
	while (b)
	{	
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	int i;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&T);
	for (i=1;i<=T;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
