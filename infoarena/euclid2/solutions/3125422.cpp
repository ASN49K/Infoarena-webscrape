#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
	while (a!=b)
	{
		if (a > b)
		{
			a -= b;
		}
		else if (a < b)
		{
			b -= a;
		}
	}

	return a;
}

int main()
{
	FILE* f = fopen("in.txt", "r");
	if (f == NULL)
	{
		printf("File could not be opened!");
		exit(-1);
	}

	int nr_perechi;
	fscanf(f, "%d", &nr_perechi);

	int unu, doi;
	FILE* g = fopen("out.txt", "w");
	if (g == NULL)
	{
		printf("Nu s-a putut deschide fisierul de output!");
		exit(1);
	}

	for (int i = 0; i < nr_perechi; i++)
	{
		fscanf(f, "%d %d", &unu, &doi);

		if (i == nr_perechi - 1)
		{
			fprintf(g, "%d", cmmdc(unu, doi));
		}
		else
		{
			fprintf(g, "%d\n", cmmdc(unu, doi));
		}
	}

	fclose(g);
	fclose(f);
	return 0;
}