#include <stdio.h>

int cmmdc(int a, int b)
{
	if(b == 0)
		return a;
	return cmmdc(b, a % b);
}

int main(void)
{
	int t, a, b;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &t);

	for(;t;t--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}
}
