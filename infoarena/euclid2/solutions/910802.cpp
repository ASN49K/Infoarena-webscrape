#include<stdio.h>

int main()
{
	int n, a, b, c, i;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%d", &n);
	for(i = 0;i < n; i++)
	{
		scanf("%d %d", &a, &b);
		while (b != 0)
		{
			c = b;
			b = a%b;
			a = c;
		}
		printf("%d\n", a);
	}
}
