#include <cstdio>

inline int cmmdc(int a, int b)
{
	int r = 1;
	while (r) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t, T, a, b;
	FILE *f1, *f2;
	f1 = fopen("euclid2.in", "r");
	f2 = fopen("euclid2.out", "w");
	fscanf(f1, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(f1, "%d%d", &a, &b);
		fprintf(f2, "%d\n", cmmdc(a, b));
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
