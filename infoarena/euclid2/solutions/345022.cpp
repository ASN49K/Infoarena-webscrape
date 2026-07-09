#include <cstdio>

#define INPUT_F "euclid2.in"
#define OUTPUT_F "euclid2.out"

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int gcdit(const int a, const int b)
{
	int x = a, y = b, r;

	while (r = x % y)
		x = y,
		y = r;

	return y;
}

int main()
{
	FILE *fin = fopen(INPUT_F, "r");
	FILE *fout =fopen(OUTPUT_F, "w");
	
	int T, x, y;
	for (fscanf(fin, "%d", &T); T; --T)
		fscanf(fin, "%d %d", &x, &y),
		fprintf(fout, "%d\n", gcd(x, y) );

	fclose(fin), fclose(fout);
	return 0;
}