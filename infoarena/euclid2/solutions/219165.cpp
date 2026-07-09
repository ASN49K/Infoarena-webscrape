/*
 * euclid2.cpp
 *
 *  Created on: Nov 5, 2008
 *      Author: stefan
 */

#include <stdio.h>

int main()
{
	unsigned long int T, a, b, tmp;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%lu", &T);
	while (T--)
	{
		scanf("%lu %lu", &a, &b);

		if (b > a)
			a = a + b - (b = a);

		while (b != 0)
		{
			tmp = b;
			b = a % b;
			a = tmp;
		}

		printf("%lu\n", a);
	}

	return 0;
}
