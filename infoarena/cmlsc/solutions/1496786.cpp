#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *input = fopen("cmlsc.in", "r");
	FILE *output = fopen("cmlsc.out", "w");

	int m, n;
	int *a, *b;
	int *result;
	int result_index = 1;

	fscanf(input, "%d %d", &m, &n);

	a = (int*)malloc(m*sizeof(int));
	b = (int*)malloc(n*sizeof(int));
	result = (int*)malloc((m + n) / 2 * sizeof(int));
	
	for (int i = 0; i < (m + n) / 2; i++)
		*(result + i) = 0;

	for (int i = 0; i < m; i++)
		fscanf(input, "%d", &a[i]);
	for (int i = 0; i < n; i++)
		fscanf(input, "%d", &b[i]);

	for (int i = 0; i < m; i++)
	{
		for (int j = result_index - 1; j < n; j++)
		{
			if (a[i] == b[j])
			{
				result[result_index] = i;
				result_index++;
				break;
			}
		}
	}

	fprintf(output, "%d\n", result_index - 1);

	for (int i = 1; i < (result_index-1)/2; i++)
	{
		fprintf(output, "%d ", a[result[i]]);
	}

	return 0;
}