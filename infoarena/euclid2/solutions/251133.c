#include <stdio.h>

int a,b,T;
int cmmdc(int a, int b)
{	
	if (!b)
		return a;
	else
		return cmmdc(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&T);
	while (T>0)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
