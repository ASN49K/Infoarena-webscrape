#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *input = fopen("cmlsc.in", "r");
	FILE *output = fopen("cmlsc.out", "w");

	long n, m;
	long *a, *b;

	long base_a, base_b;
	long *c;
	long common_index;
	long check_fwd;
	bool found;

	fscanf(input, "%ld %ld", &n, &m);

	a = (long*)malloc(n*sizeof(long));
	b = (long*)malloc(m*sizeof(long));
	c = (long*)malloc((n + m) / 2 * sizeof(long));

	for (long i = 0; i < n; i++)
		fscanf(input, "%ld", a[i]);

	for (long i = 0; i < m; i++)
		fscanf(input, "%ld", b[i]);

	common_index = 0;
	while (base_a < n && base_b < m)
	{
		for (check_fwd = 0; check_fwd + base_a < n && check_fwd + base_b < m && !found; check_fwd++)
		{
			found = false;
			for (long i = 0; i < check_fwd && !found; i++)
			{
				for (long j = 0; j < check_fwd && !found; j++)
				{
					if (a[base_a + i] == b[base_b + j])
					{
						c[common_index] = a[base_a + i];
						common_index++;
						found = true;
						base_a += (i + 1);
						base_b += (j + 1);
					}
				}
			}
		}
	}

	fprintf(output, "%ld\n", common_index - 1);
	for (long i = 0; i < common_index; i++)
		fprintf(output, "%ld ", c[i]);

	return 0;
}