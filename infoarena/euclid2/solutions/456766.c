/*
 * euclid_test.c
 *
 *  Created on: May 16, 2010
int main() *      Author: Adrian
 */

#include <stdio.h>
long eucl(long a,long b) {
	while(a!=b) {
		if (a>b) a=a-b;
		else b=b-a;
	}
	return a;
}
int main() {
	long t,i,a,b;
	scanf("%ld",&t);
	for(i=1;i<=t;i++) {
		scanf("%ld %ld", &a,&b);
		printf("%ld\n",eucl(a,b));
	}
	return 0;
}
