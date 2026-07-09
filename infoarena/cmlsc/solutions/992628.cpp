#include <stdio.h>

int main()
{
	freopen("euclid3.in", "r", stdin);
	freopen("euclid3.out", "w", stdout);

	int t, aa, bb, c;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d %d", &aa, &bb, &c);

		int a = aa, b = bb, r, rx, ry;
		int ax = 1, ay = 0;
		int bx = 0, by = 1;

		while (b != 0)
		{
			r = a % b;
			rx = ax - bx * (a / b);
			ry = ay - by * (a / b);

			a = b; ax = bx; ay = by;
			b = r; bx = rx; by = ry;
		}

		if (c % a != 0)
		{
			printf("0 0\n");
		}
		else
		{
			printf("%d %d\n", ax * c / a, ay * c / a);
		}
	}

	return 0;
}