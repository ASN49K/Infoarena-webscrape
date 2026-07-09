#include <cstdio>

int cmmdc(int a, int b)
{
	int r;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t, x, y;
	
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", cmmdc(x, y));
	}
	
	return 0;
}
