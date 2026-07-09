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
		fscanf(input, "%ld", &a[i]);

	for (long i = 0; i < m; i++)
		fscanf(input, "%ld", &b[i]);

	common_index = 0;
	base_a = 0;
	base_b = 0;
	found = false;
	while (base_a < n && base_b < m)
	{
		found = false;
		for (check_fwd = 0; !found && (base_a + check_fwd < n || base_b + check_fwd < m); check_fwd++) //check_fwd + base_a < n && check_fwd + base_b < m &&
		{
			for (int i = 0; i <= check_fwd && !found; i++)
			{
				if (base_a + i < n && base_b + check_fwd < m && a[base_a + i] == b[base_b + check_fwd])
				{
					c[common_index] = a[base_a + i];
					printf("%ld, ", c[common_index]);
					common_index++;
					found = true;
					base_a += (i + 1);
					base_b += (check_fwd + 1);
				}
				else
				{
					if (base_a + check_fwd < n && base_b + i < m && a[base_a + check_fwd] == b[base_b + i])
					{
						c[common_index] = a[base_a + check_fwd];
						printf("%ld, ", c[common_index]);
						common_index++;
						found = true;
						base_a += (i + 1);
						base_b += (check_fwd + 1);
					}

				}
			}

		}
	}

	fprintf(output, "%ld\n", common_index);
	for (long i = 0; i < common_index; i++)
		fprintf(output, "%ld ", c[i]);

	printf("\nDone...\nPress any key");
	getchar();

	return 0;
}