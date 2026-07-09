#include <stdio.h>

long a, b;

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%ld %ld", &a, &b);

	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}

	printf("%ld\n", a);

	return 0;
}