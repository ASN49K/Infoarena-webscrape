#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int euclid(int, int);

int main(int argc, char argv[])
{
	FILE *in, *out;
	in = fopen("euclid2.in", "r");
	out = fopen("euclid2.out", "w");
	
	int a = 0, b = 0, T = 0;
	int gcd = 0;
	fscanf(in, "%d", &T);
	
	for (int i = 0; i < T; i++) {
		fscanf(in, "%d %d", &a, &b);
		gcd = euclid(a, b);
		fprintf(out, "%d\n", gcd);
	}
	fclose(in);
	fclose(out);
	
	return 0;
}

int euclid(int a, int b)
{
    while(a) {
        b = b % a;
        a = a + b - (b = a);
    }
    return b;
}