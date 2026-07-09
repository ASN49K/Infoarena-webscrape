/*
 * gcd.c
 *
 *  Created on: Jun 16, 2011
 *      Author: marius
 */

#include <stdio.h>

int a, b, T;

int gcd( int a, int b){
	if (!b) return a;
	return gcd (b, a % b);
}
int main (void){
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.in", "w", stdout);

	scanf ("%d", &T);
	for ( ; T; T--){
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a,b));
	}

	return 0;
}
