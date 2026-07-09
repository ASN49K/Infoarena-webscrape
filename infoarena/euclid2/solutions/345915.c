#include <stdio.h>

int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int n, a, b;

	in = fopen("euclid2.in", "r");
	out = fopen("euclid2.out", "w");

	fscanf(in, "%d", &n);

	while(n--) {
		fscanf(in, "%d %d", &a, &b);
		fprintf(out, "%d\n", gcd(a, b));
	}

	return 0;
}
