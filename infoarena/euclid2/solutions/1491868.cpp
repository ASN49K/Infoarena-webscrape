#include <stdio.h>

long gcd(long a, long b)
{
	while ((a > b && a % b != 0) || (b > a && b % a != 0))
	{
		if (a > b)
			a = a % b;
		else b = b % a;
	}
	return (a < b) ? (a) : (b);
}

int main()
{
	FILE *input = fopen("euclid2.in", "r");
	FILE *output = fopen("euclid2.out", "w");

	long T;
	long a, b;

	// scan number of pairs
	fscanf(input, "%ld", &T);


	// deal with them
	for (long i = 0; i < T; i++)
	{
		fscanf(input, "%ld %ld", &a, &b);
		fprintf(output, "%ld\n", gcd(a, b));
	}

	return 0;
}