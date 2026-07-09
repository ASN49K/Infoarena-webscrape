#include <iostream>

int SimpleCmmdc(int a, int b)
{
	int min = 0xFFFFFF;

	if (a < b)
		min = a;
	else
		min = b;

	for (int i = min - 1; i >= 1; i--)
	{
		if (a%i == 0 && b%i == 0)
			return i;
	}
}


int main()
{
	int a, b,n;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		printf("%d\n", SimpleCmmdc(a, b));
	}

	return 0;
}