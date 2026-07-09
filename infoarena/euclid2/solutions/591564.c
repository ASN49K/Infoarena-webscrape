/*
 * euclid01.c
 *
 *  Created on: 24 May 2011
 *      Author: razvan
 */

#include <stdio.h>

void main(){

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int T, a, b, i;
	scanf("%d", &T);
	for( i = 0; i < T; i++){
		scanf("%d %d", &a, &b);

		while(a && b){
			if(a>b)
				a = a % b;
			else
				b = b % a;
		}
		if(a)
			printf("%d\n", a);
		else
			printf("%d\n", b);
	}


}
