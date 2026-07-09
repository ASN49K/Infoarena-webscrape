#include <stdio.h>

long n, i;
long euclid(int x, int y)
{
	if(!y)
		return x;
	return euclid(y, x%y);
}
int main()
{
	long x, y;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%ld %ld", &x, &y);
		printf("%ld\n", euclid(x, y));
	}

	return 0;
}