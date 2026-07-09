/*
 * gcd.c
 *
 *  Created on: Jun 16, 2011
 *      Author: marius
 */

#include <stdio.h>

long int a, b, T;

long int gcd( long int a, long int b){
	if (!b) return a;
	return gcd (b, a%b);
}
int main (void){
	freopen ("euclid2.in", "r", stdin);
	freopen ("euclid2.in", "w", stdout);

	scanf ("%ld", &T);
	for ( ; T; T--){
		scanf("%ld %ld", &a, &b);
		printf("%ld\n", gcd(a,b));
	}

	return 0;
}
