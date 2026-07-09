#define K_N_MAX 1025
#include <stdio.h>

int n, m;
short v1[K_N_MAX], v2[K_N_MAX];
short sub[K_N_MAX][K_N_MAX];

FILE* in = fopen("cmlsc.in", "r");
FILE* out = fopen("cmlsc.out", "w");

void readData() 
{
	int i;

	fscanf(in, "%d %d", &n, &m);

	for (i = 0; i < n; i++) 
	{
		fscanf(in, "%d", &v1[i]);
	}

	for (i = 0; i < m; i++)
	{
		fscanf(in, "%d", &v2[i]);
	}
}

void solve() 
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (v1[i-1] == v2[j-1])
			{
				sub[i][j] = sub[i - 1][j - 1] + 1;
			}
			else 
			{
				sub[i][j] = (sub[i - 1][j] > sub[i][j - 1]) ? sub[i - 1][j] : sub[i][j - 1];
			}
		}
	}
	
	fprintf(out, "%d\n", sub[n][m]);
}

void printSolution(int i, int j, short current)
{
	if (i > 0 && j > 0)
	{
		if (sub[i][j - 1] == current)
		{
			printSolution(i, j - 1, current);
		}
		else if (sub[i - 1][j] == current)
		{
			printSolution(i - 1, j, current);
		}
		else
		{
			printSolution(i - 1, j - 1, current - 1);
			fprintf(out, "%d ", v1[i - 1]);
		}
	}
}

void printMatrix()
{
	int i, j;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			fprintf(out, "%d ", sub[i][j]);
		}

		fprintf(out, "\n");
	}
}

int main(void)
{
	readData();
	solve();
	printSolution(n, m, sub[n][m]);

	fclose(in);
	fclose(out);

	return 0;
}


/* Our greatest weakness lies in giving up. The most certain way to succeed is always to try just one more time.*/