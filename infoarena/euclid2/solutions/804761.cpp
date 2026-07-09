#include <iostream>
#include <algorithm>

int T, a, b;

int main(void)
{
	int i;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d", &T);
	for (int j=1; j<=T; j++)
	{		
		scanf("%d %d", &a, &b);
		for (i = min(a,b); i; i--)
			if (a % i == 0 && b % i == 0)
			{
				printf("%d\n", i);
				break;
			}
	}

	return 0;
}
