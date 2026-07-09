#include <stdio.h>

int main()
{
	FILE *in = fopen("nim.in", "rt"), *out = fopen("nim.out", "wt");

	int t, n, x;
	fscanf(in, "%d", &t);

	while(t--) {
		int xor_sum = 0;
		fscanf(in, "%d", &n);
		for (int i = 1; i <= n; ++i) {
			fscanf(in, "%d", &x);
			xor_sum ^= x;
		}
		if (xor_sum)
			fprintf(out, "DA\n");
		else
			fprintf(out, "NU\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}