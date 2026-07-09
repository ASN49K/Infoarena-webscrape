#include <stdio.h>
FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");
int a,b,t;

int gcd(int a, int b){
	int c;
	while (b) {
		c= a%b;
		a=b;
		b=c;
	}
	return a;
}

int main () {

	fscanf(f,"%d", &t);
	for (; t; --t) {
		fscanf(f,"%d %d", &a, &b);
		fprintf(g,"%d\n", gcd(a, b));
	}

	fclose(f);
	fclose(g);
	return 0;
}
