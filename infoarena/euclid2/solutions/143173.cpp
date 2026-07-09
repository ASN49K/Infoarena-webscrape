#include <stdio.h>

int gcb(int x, int y)
{
	if (!y)  return y;
	return gcb(y, x % y);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a, b;
	scanf("%d %d",&a, &b);
	printf("%d\n",gcb(a,b));
	return 0;
}