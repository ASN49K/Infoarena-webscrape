#include <cstdio>
#include <string>

#define NONE	0
#define UP		1
#define OBLIQUE 2
#define LEFT	3

struct cell
{
	int length  = 0;
	int dir = NONE;
};

int main()
{
	//initializing
	FILE *in = fopen("cmlsc.in", "r"), *out = fopen("cmlsc.out", "w");
	int m, n;

	fscanf(in, "%d %d", &m, &n);

	unsigned short *a, *b;
	a = new unsigned short[m];
	b = new unsigned short[n];

	cell **matrix;
	matrix = new cell*[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		matrix[i] = new cell[n + 1];
	}

	for (int i = 0; i < m; i++)
	{
		fscanf(in, "%d", &a[i]);
	}


	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%d", &b[i]);
	}

	//algorithm
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				matrix[i][j].length = matrix[i - 1][j - 1].length + 1;
				matrix[i][j].dir	= OBLIQUE;
			}
			else
			{
				if (matrix[i - 1][j].length > matrix[i][j - 1].length)
				{
					matrix[i][j].length = matrix[i - 1][j].length;
					matrix[i][j].dir	= UP;
				}
				else
				{
					matrix[i][j].length = matrix[i][j - 1].length;
					matrix[i][j].dir	= LEFT;
				}
			}
		}
	}

	//storing result

	int i = m, j = n;
	unsigned short *result = new unsigned short[matrix[m][n].length];
	while (matrix[i][j].dir != NONE)
	{
		cell currElement = matrix[i][j];
		if (currElement.dir == OBLIQUE)
		{
			result[currElement.length - 1] = a[i - 1];
			i--; j--;
		}
		else if (currElement.dir == LEFT)
		{
			j--;
		}
		else if (currElement.dir == UP)
		{
			i--;
		}
	}

	//output

	fprintf(out, "%d\n", matrix[m][n].length);
	for (int i = 0; i < matrix[m][n].length; i++)
	{
		fprintf(out, "%d ", result[i]);
	}
	fprintf(out, "\n");

	//cleaning up
	/*for (int i = 0; i < m + 1; i++)
		delete[] matrix[i];
	delete[] matrix;

	delete[] a;
	delete[] b;

	delete[] result;
*/
	return 0;
}