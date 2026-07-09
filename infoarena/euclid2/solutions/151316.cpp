#include <stdio.h>

int a, b;

int cmmdc(int a, int b)
{
	if(b == 0) return a;
	else return cmmdc(b, a % b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d%d", &a, &b);
	printf("%d\n", cmmdc(a, b));

	return 0;
}
