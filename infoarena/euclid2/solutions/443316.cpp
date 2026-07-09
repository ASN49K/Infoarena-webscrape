#include <iostream>

using namespace std;

int euclid(int x, int y)
{
	if (!y)
		return x;
	return euclid(y, x % y);
}

int main()
{
	FILE *fin = fopen("euclid2.in", "r"), *fout = fopen("euclid2.out", "w");
	int n, a, b;
	
	fscanf(fin, "%d", &n);
	
	for (; n; --n)
	{
		fscanf(fin, "%d %d", &a, &b);
		fprintf(fout, "%d\n", euclid(a, b));
	}

	fclose(fout);
	return 0;
}