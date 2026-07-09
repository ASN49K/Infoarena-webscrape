#include <stdio.h>

int gcd(int a, int b)
{
	int tmp;
	while(b) {
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	int a, b, T;
	for(scanf("%d", &T); T > 0; --T) {
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}

	return 0;
}
