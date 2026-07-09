#include <stdio.h>

#define MAX_N 1025

struct Cell
{
	int val = 0;
	bool use = false;
	int prevY = -1;
	int prevX = -1;
};

FILE* fin;
FILE* fout;

int m, n;

int aValues[MAX_N];
int bValues[MAX_N];

Cell matrix[MAX_N][MAX_N];

int maxY = 0;
int maxX = 0;

int solution[MAX_N];
int solLength = 0;

void LoadFiles()
{
	fin = fopen("cmlsc.in", "r");
	fout = fopen("cmlsc.out", "w");
}

void Init()
{
	LoadFiles();
}

void Read()
{
	fscanf(fin, "%d %d", &m, &n);

	for (int i = 1;i <= m;i++)
	{
		fscanf(fin, "%d", &aValues[i]);
	}

	for (int i = 1;i <= n;i++)
	{
		fscanf(fin, "%d", &bValues[i]);
	}
}

int Max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

void CreateSolution()
{
	int crtY = maxY;
	int crtX = maxX;

	int ty;
	int tx;

	int index = 0;

	while (matrix[crtY][crtX].val != 0)
	{
		if (matrix[crtY][crtX].use)
		{
			solution[index++] = aValues[crtY];
		}

		ty = crtY;
		tx = crtX;

		crtY = matrix[ty][tx].prevY;
		crtX = matrix[ty][tx].prevX;
	}

	solLength = index;
}

void Solve()
{
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (aValues[i] == bValues[j])
			{
				matrix[i][j].val = Max(matrix[i - 1][j].val, matrix[i][j - 1].val) + 1;
				matrix[i][j].use = true;
			}
			else
			{
				matrix[i][j].val = Max(matrix[i - 1][j].val, matrix[i][j - 1].val);
				matrix[i][j].use = false;
			}

			if (matrix[i - 1][j].val > matrix[i][j - 1].val)
			{
				matrix[i][j].prevY = i - 1;
				matrix[i][j].prevX = j;
			}
			else
			{
				matrix[i][j].prevY = i;
				matrix[i][j].prevX = j-1;
			}

			if (matrix[i][j].val > matrix[maxY][maxX].val)
			{
				maxY = i;
				maxX = j;
			}
		}
	}

	CreateSolution();
}

void Write1()
{
	fprintf(fout, "%d\n", solLength);
}

void Write2()
{
	for (int i = solLength - 1;i >= 0;i--)
	{
		fprintf(fout, "%d ", solution[i]);
	}
}

void Write()
{
	Write1();
	Write2();
}

void CloseFiles()
{
	fclose(fin);
	fclose(fout);
}

void Terminate()
{
	CloseFiles();
}

int main(void)
{
	Init();
	Read();
	Solve();
	Write();
	Terminate();

	return 0;
}