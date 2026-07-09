#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int t, a, b;
	FILE *f, *g;

	f = fopen("euclid2.in", "r");
	g = fopen("euclid2.out", "w");
	fscanf(f, "%d" ,&t);
	for (int i = 0; i < t; ++i) {
		fscanf(f, "%d %d", &a, &b);
		while(a && b) {
			if (a > b)
				a %= b;
			else
				b %= a;
	}
		fprintf(g, "%d\n", a + b);
	}
	fclose(f);
	fclose(g);

	return 0;
}
