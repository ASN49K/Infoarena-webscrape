#include <stdio.h>

int cmmdc(int a,int b)
{
	if (!b) return a;
	return cmmdc(b,a%b);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdin);

	int a,b;

	scanf("%d%d", &a,&b);

	printf("%d\n", cmmdc(a,b));

	return 0;
}