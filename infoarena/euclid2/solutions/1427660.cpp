#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	int r;

	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	FILE * in = fopen("euclid2.in" , "r");
	FILE * out = fopen("euclid2.out", "w");

	int n, x, y, r;

	fscanf(in, "%d", &n);

	while(n--)
	{
		fscanf(in , "%d%d", &x, &y);
		r = gcd(x, y);
		fprintf(out, "%d\n", r);
	}

	fclose(in);
	fclose(out);
	return 0;
}
