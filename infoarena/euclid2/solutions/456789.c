/*
 * euclid_test2.c
 *
 *  Created on: May 16, 2010
int main() *      Author: Adrian
 */

#include <stdio.h>
long eucl(long a,long b) {
	long aux;
	while(b) {
		aux=a;
		a=b;
		b=aux%b;
	}
	return a;
}
int main() {
	long t,i,a,b;
	FILE *in=fopen("euclid2.in","r"), *out=fopen("euclid2.out","w");
	fscanf(in, "%ld",&t);
	for(i=1;i<=t;i++) {
		fscanf(in, "%ld %ld", &a,&b);
		fprintf(out, "%ld\n",eucl(a,b));
	}
	return 0;
}
