#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030], b[1030], n, m;
int c[1024][1024], sub_max[1024], k;

void Back(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	else if (a[i] == b[j])
	{
		Back(i - 1, j - 1);
		sub_max[++k] = a[i];
	}
	else if (c[i][j - 1] > c[i - 1][j])
		Back(i, j - 1);
	else Back(i - 1, j);
}

int main()
{
	int i, j;

	fin >> n >> m;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	for (i = 1; i <= m; i++)
		fin >> b[i];

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			if (a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}

	Back(n, m);
	fout << k << "\n";
	for (i = 1; i <= k; i++)
		fout << sub_max[i] << " ";
	return 0;
}