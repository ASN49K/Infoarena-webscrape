/*
 * euclid.c
 *
 *  Created on: Jun 16, 2011
 *      Author: mihai
 */

#include <stdio.h>

int nr, a, b;

int euclid(int a, int b) {

	if (!b)
		return a;
	return euclid(b, a % b);
}

int main() {

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &nr);

	for (; nr; nr--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", euclid(a, b));
	}
	return 0;
}
