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
	bool finally_over = false;

	fscanf(input, "%ld %ld", &n, &m);

	a = (long*)malloc(n*sizeof(long));
	b = (long*)malloc(m*sizeof(long));
	c = (long*)malloc((n + m) / 2 * sizeof(long));

	for (long i = 0; i < n; i++)
		fscanf(input, "%ld", &a[i]);

	for (long i = 0; i < m; i++)
		fscanf(input, "%ld", &b[i]);

	common_index = 0;
	base_a = 0;
	base_b = 0;
	found = false;
	finally_over = false;
	
	while (base_a < n && base_b < m && !finally_over)
	{
		found = false;
		for (check_fwd = 0; (base_a + check_fwd < n || base_b + check_fwd < m) && !found; check_fwd++)
		{
			for (long i = 0; i <= check_fwd && base_a + i < n && !found; i++)
			{
				if (a[base_a + i] == b[base_b + check_fwd])
				{
					found = true;
					c[common_index] = a[base_a + i];
					common_index++;
					base_a += i + 1;
					base_b += check_fwd + 1;
					//printf("%ld,", c[common_index - 1]);
				}
			}
			for (long i = 0; i <= check_fwd && base_b + i < m && !found; i++)
			{
				if (b[base_b + i] == a[base_a + check_fwd])
				{
					found = true;
					c[common_index] = b[base_b + i];
					common_index++;
					base_a += check_fwd + 1;
					base_b += i + 1;
					//printf("%ld,", c[common_index - 1]);
				}
			}
		}
		if (!found)
			finally_over = true;
	}

	//printf("\n%ld\n", common_index);

	fprintf(output, "%ld\n", common_index);
	for (long i = 0; i < common_index; i++)
		fprintf(output, "%ld ", c[i]);

	return 0;
}