#define _CRT_SECURE_NO_WARNINGS
#define ALEX_THE_DUDE
#define NMAX 1025

#include <stdio.h>
using namespace std;

FILE *fin, *fout;
typedef unsigned short byte;
int n, m;
byte v1[NMAX], v2[NMAX], cmlsc[NMAX][NMAX], solution[NMAX];


void read()
{
	int i;
	fscanf(fin, "%d %d", &n, &m);

	for (i = 0; i < n; i++)
		fscanf(fin, "%hu", &v1[i]);

	for (i = 0; i < m; i++)
		fscanf(fin, "%hu", &v2[i]);
}

int length;

void solve()
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cmlsc[i + 1][j + 1] = ((v1[i] == v2[j]) ? 1 : 0) + ((cmlsc[i][j + 1] > cmlsc[i + 1][j]) ? cmlsc[i][j + 1] : cmlsc[i + 1][j]);
		}
	}
}

void print()
{
	int i = n, j = m, k = 0;
	
	fprintf(fout, "%hu\n", cmlsc[n][m]);

	while (cmlsc[i][j] != 0)
	{
		if (cmlsc[i][j] - cmlsc[i][j - 1] == 0)
		{
			j--;
		}
		else if (cmlsc[i][j] - cmlsc[i - 1][j] == 0)
		{
			i--;
		}
		else
		{
			solution[k++] = v1[i - 1];
			i--;
			j--;
		}
	}

	k--;
	while (k >= 0)
	{
		fprintf(fout, "%hu ", solution[k--]);
	}
}

int main()
{
	fin = fopen("cmlsc.in", "r");
	fout = fopen("cmlsc.out", "w");

	read();
	solve();
	print();

	fclose(fin);
	fclose(fout);
	return 0;
}