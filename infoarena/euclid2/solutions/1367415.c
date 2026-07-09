#include <stdio.h>

#define IN_FILE "euclid2.in"
#define OUT_FILE "euclid2.out"

long long cmmdc(long long a, long long b)
{
	long long r;

	do {
		r = a % b;
		a = b;
		b = r;
	} while(r != 0);

	return a;
}

int main()
{
	FILE *in = fopen(IN_FILE, "r");
	FILE *out = fopen(OUT_FILE, "w");

	if(!in)
		return 0;

	long long n;
	fscanf(in, "%lld", &n);

	for(int i = 0; i < n; i++) {
		long long a, b;
		fscanf(in, "%lld%lld", &a, &b);
		fprintf(out, "%lld\n", cmmdc(a, b));
	}

	return 0;
}