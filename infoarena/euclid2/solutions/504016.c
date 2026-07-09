#include <stdio.h>

int cmmdc(int a, int b);

int main(void)
{
	int T, i;

	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	scanf("%d",&T);
	
	for (i=0;i<T;++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	
	return 0;
}

int cmmdc(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = b;
		b = a%b;
		a = c;
	}
	return a;
}