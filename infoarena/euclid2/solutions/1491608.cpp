#include <stdio.h>

long gcd(long a, long b)
{
	while (a != b)
	{
		if (a > b && a - b > 0)
			a = a - b;
		else b = b - a;
	}
	return a;
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
		//scanf("%ld %ld", &a, &b);
		//printf("%ld", gcd(a, b));
	}

	return 0;
}