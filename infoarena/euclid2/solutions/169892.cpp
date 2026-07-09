#include<stdio.h>

#define input "euclid2.in"
#define output "euclid2.out"

int euclid (long long unsigned a, long long unsigned b);

int n;

int main()
{
	FILE *in, *out;

	in = fopen (input, "r");
	out = fopen (output, "w");

	fscanf(in, "%d", &n);

	int i;
	long long unsigned x, y;

	for(i=1; i<=n; i++)
	{
		fscanf(in, "%lld%lld", &x, &y);

		fprintf(out, "%d\n", euclid(x, y));
	}

	return 0;

}

int euclid (long long unsigned a, long long unsigned b)
{
	if(!b)

		return a;

	return euclid(b, a%b);

}



