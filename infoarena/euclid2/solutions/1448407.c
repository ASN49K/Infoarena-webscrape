#include <stdio.h>

int euclid(int x, int y);

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	int i, n;
	int a, b;
	scanf("%d", &n);
	for(i=0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", euclid(a, b));
	}
}

int euclid(int x, int y)
{
	if(y == 0)
	{
		return x;
	}
	else
	{
		return euclid(y, x % y);
	}
}
